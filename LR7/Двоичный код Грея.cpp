#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<string> GrayCode(int n) {
    if (n <= 0) {
        vector<string> res;
        res.push_back("");
        return res;
    }

    vector<string> s = GrayCode(n - 1);
    vector<string> res;
    for (int i = 0; i <s.size(); i++) {
        res.push_back("0" + s[i]);
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        res.push_back("1" +s[i]);
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> G = GrayCode(n);
    for (const auto& code : G) {
        cout << code << endl;
    }

    return 0;
}

