#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> chet(k, 0), nechet(k, 0);
    for (int i = 1; i < 10; i++) {
        if (i % 2 == 0) {
            chet[i % k] += 1;
        }
        else {
            nechet[i % k] += 1;
        }
    }

    for (int len = 1; len < n; len++) {
        vector<int> chet1(k, 0), nechet1(k, 0);
        for (int cur_ost = 0; cur_ost < k; cur_ost++) {
            for (int next_num = 0; next_num < 10; next_num++) {
                int next_ost = (cur_ost * 10 + next_num) % k;
                if (next_num % 2 == 0) {
                    chet1[next_ost] += nechet[cur_ost];
                    chet1[next_ost] %= 1000000007;
                }
                else {
                    nechet1[next_ost] += chet[cur_ost];
                    nechet1[next_ost] %= 1000000007;
                }
            }
        }
        chet = chet1;
        nechet = nechet1;
    }

    int answer = (chet[0] + nechet[0]) % 1000000007;
    cout << answer;

    return 0;
}