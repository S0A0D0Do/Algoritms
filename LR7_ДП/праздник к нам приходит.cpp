#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Be {
    long long int first, second;
};

long long int Min(long long int a, long long int b) {
    if (a > b)
        return b;
    return a;
}

int main() {
    long long int n;
    cin >> n;

    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<long long int, Be> p;
    for (long long int i = 0; i < n; i++) {
        if (!p.count(a[i])) {
            p[a[i]] = {i, i};
        } else {
            p[a[i]].second = i;
        }
    }

    map<long long int, long long int> cnt;
    for (long long int i = 0; i < n; i++) {
        if (cnt.count(a[i]))
            cnt[a[i]] += 1;
        else
            cnt[a[i]] = 1;
    }
    vector<long long int> num;
    sort(a.begin(), a.end());
    for (long long int i = 0; i < n; i++) {
        if (num.empty() or num.back() != a[i])
            num.push_back(a[i]);
    }

    vector<vector<long long int>> dp(2, vector<long long int>(num.size(), 1000000007));
    dp[1][0] = p[num[0]].second + cnt[num[0]];
    dp[0][0] = dp[1][0] + p[num[0]].second - p[num[0]].first;

    long long int fs, ff, sf, ss;
    for (long long int i = 1; i < num.size(); i++) {
        long long int dist = p[num[i]].second - p[num[i]].first;
        fs = abs(p[num[i - 1]].second - p[num[i]].second) + dist + cnt[num[i]];
        ff = abs(p[num[i - 1]].second - p[num[i]].first) + dist + cnt[num[i]];
        sf = abs(p[num[i - 1]].first - p[num[i]].first) + dist + cnt[num[i]];
        ss = abs(p[num[i - 1]].first - p[num[i]].second) + dist + cnt[num[i]];
        dp[1][i] = Min(dp[1][i - 1] + ff, dp[0][i - 1] + sf);
        dp[0][i] = Min(dp[1][i - 1] + fs, dp[0][i - 1] + ss);
    }
    cout << Min(dp[0][num.size() - 1], dp[1][num.size() - 1]);

    return 0;
}
