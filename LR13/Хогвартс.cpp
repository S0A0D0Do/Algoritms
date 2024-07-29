#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefixF(string s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> N(n, 0);
    vector<int> pi = prefixF(s);
    for (int i = 1; i < n; i++) {
        N[i] = pi[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << N[i] << " ";
    }

    return 0;
}
