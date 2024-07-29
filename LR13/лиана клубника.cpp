#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    int count = 0;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        string s1 = s.substr(a-1, c);
        string s2 = s.substr(b-1, c);

        if (s1 == s2)
            count++;
    }

    cout << count << endl;

    return 0;
}

