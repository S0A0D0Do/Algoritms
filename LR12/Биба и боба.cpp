#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    vector<int> control(2*n, 0);
    
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += control[s[i] - i + n];
        control[s[i] - i + n]++;
    }
    
    cout << res;
    
    return 0;
}
