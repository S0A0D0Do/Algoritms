#include "blazingio.hpp"
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s1(311);
    vector<int> s2(311);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s1[a%311]++;
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        s2[b%311]++;
    }

    bool is_equal = true;
    for (int i = 0; i < 311; i++) {
        if (s1[i] != s2[i]) {
            is_equal = false;
            break;
        }
    }

    if (is_equal) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
