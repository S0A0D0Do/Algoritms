#include <iostream>
#include <vector>
using namespace std;

struct coord {
    long long int x;
    long long int y;
};

int main() {
    long long int n, m;
    cin >> n >> m;
    vector<vector<long long int>> array(n, vector<long long int>(m));
    vector<vector<long long int>> masha_array(n, vector<long long int>(m, 0));
    vector<vector<long long int>> dasha_array(n, vector<long long int>(m, 0));
    for (long long int i = 0; i < n; ++i) {
        for (long long int j = 0; j < m; ++j) {
            cin >> array[i][j];
        }
    }
    long long int q;
    cin >> q;
    vector<coord> request(q);
    for (long long int i = 0; i < q; ++i) {
        coord tmp;
        cin >> tmp.x >> tmp.y;
        request[i] = tmp;
    }
    masha_array[0][0] = array[0][0];
    dasha_array[n - 1][m - 1] = array[n - 1][m - 1];
    for (long long int i = 1; i < m; ++i) {
        masha_array[0][i] = array[0][i] + masha_array[0][i - 1];
        dasha_array[n - 1][m - 1 - i] = array[n - 1][m - 1 - i] + dasha_array[n - 1][m - i];
    }
    for (long long int i = 1; i < n; ++i) {
        masha_array[i][0] = array[i][0] + masha_array[i - 1][0];
        dasha_array[n - 1 - i][m - 1] = array[n - 1 - i][m - 1] + dasha_array[n - i][m - 1];
    }

    for (long long int i = 1; i < n; ++i) {
        for (long long int j = 1; j < m; ++j) {
            masha_array[i][j] = array[i][j] + max(masha_array[i - 1][j], masha_array[i][j - 1]);
            dasha_array[n - 1 - i][m - 1 - j] = array[n - 1 - i][m - 1 - j] + max(dasha_array[n - i][m - 1 - j], dasha_array[n - i - 1][m - j]);
        }
    }

    for (long long int i = 0; i < q; ++i) {
        long long int x1, y1;
        x1 = request[i].x;
        y1 = request[i].y;
        cout << dasha_array[x1][y1] + masha_array[x1][y1] - array[x1][y1] << '\n';
    }
}
