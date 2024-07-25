#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void R(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > 9) {
            a[i+1] += a[i] / 10;
            a[i] %= 10;
        }
    }
    while (a.back() > 9) {
        a.push_back(a.back() / 10);
        a[a.size() - 2] %= 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(1, 0);
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        if (s.size() > a.size()) {
            a.resize(s.size(), 0);
        }
        for (int j = 0; j < s.size(); j++) {
            a[j] += (s[j] - '0');
        }
    }
    
    R(a);

    while (!a.empty() && a.back() == 0) {
        a.pop_back();
    }
    
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i];
    }
}
    
  
