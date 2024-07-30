#include <iostream>
#include <vector>
using namespace std;

vector<int> F(vector<int>& a) {
    int n = a.size();
    vector<int> l(n, 0);
    l[0] = a[0];
    for (int i = 1; i < n; i++) {
        l[i] = l[i - 1] + a[i];
    }

    reverse(a.begin(), a.end());
    vector<int> r(n, 0);
    r[0] = a[0];
    for (int i = 1; i < n; i++) {
        r[i] = r[i - 1] + a[i];
    }

    vector<int> ans(n, 0);
    for (int len = 1; len <= n; len++) {
        for (int ll = 1; ll < len; ll++) {
            ans[len - 1] = max(ans[len - 1], l[ll - 1] + r[len - ll - 1]);
        }
        ans[len - 1] = max(ans[len - 1], l[len - 1]);
        ans[len - 1] = max(ans[len - 1], r[len - 1]);
    }
    return ans;
}

int main() {

    int n, m, q;
    cin >> n >> m;

    vector<vector<int>> a;
    vector<int> dp(m + 1, 0);
    vector<vector<int>> best(n);

    for (int i = 0; i < n; i++) {
        cin >> q;
        vector<int> aa(q);
        for (int j = 0; j < q; j++) {
            cin >> aa[j];
        }
        a.push_back(aa);
    }

    for (int i = 0; i < n; i++) {
        best[i] = F(a[i]);
    }

    for (int i = 1; i <= a[0].size(); i++) {
        if(i > m) {
            break;
        }
        dp[i] = best[0][i - 1];
    }

    for (int i = 1; i < n; i++) {
        vector<int> dp1(m + 1);
        for (int j = 0; j <= m; j++) {
            dp1[j] = dp[j];
        }
        for (int j = 1; j <= best[i].size(); j++) {
            if (j > m) break;
            dp1[j] = max(dp1[j], best[i][j - 1]);
        }


        for (int j = 1; j <= m; j++) {
            if(dp[j] == 0) {
                break;
            }
            for (int k = 0; k < best[i].size(); k++) {
                if (j + k + 1 >  m) {
                    break;
                }
                dp1[j + k + 1] = max(dp1[j + k + 1], dp[j] + best[i][k]);
            }
        }
        dp = dp1;
    }
    cout << dp[m];

    return 0;
}