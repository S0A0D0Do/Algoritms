#include <iostream>
#include <vector>
using namespace std;

const int MAX_HEIGHT = 5,MAX_MASK = (1 << MAX_HEIGHT) - 1;
bool adj_mask[MAX_MASK + 1][MAX_MASK + 1];
int dp[35][1 << MAX_HEIGHT];
int MASK;


bool isComp(int prv, int cur, int n){
    for (int bit = 0; bit < n - 1; ++bit) {
        int sum = ((prv >> bit) & 1) + ((prv >> (bit + 1)) & 1) +
                  ((cur >> bit) & 1) + ((cur >> (bit + 1)) & 1);
        if (sum == 0 || sum == 4) {
            return false;
        }
    }
    return true;
}

void precalc_matrix(int n) {
    for (int i = 0; i <= MASK; ++i)
        for (int j = 0; j <= MASK; ++j)
            adj_mask[i][j] = isComp(i, j,n);
}

void solve(int n, int m) {
    for (int mask = 0; mask <= MASK; ++mask) {
        dp[0][mask] = 1;
    }
    for (int k = 1; k < m; ++k) {
        for (int i = 0; i <= MASK; ++i) {
            for (int j = 0; j <= MASK; ++j) {
                if (adj_mask[i][j]) {
                    dp[k][j] += dp[k - 1][i];
                }
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    MASK = (1 << n) - 1;
    precalc_matrix(n);
    solve(n,m);
    int res = 0;
    for (int mask = 0; mask <= MASK; ++mask) {
        res += dp[m - 1][mask];
    }
    cout << res;
    return 0;
}