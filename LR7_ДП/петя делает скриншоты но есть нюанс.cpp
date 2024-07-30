#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

long long int Min(long long int a, long long int b) {
    if (a > b)
        return b;
    return a;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    char* arr = new char[m];
    std::string s;
    long long int* arr2 = new long long int[m+1];
    long long int res = 0, x = 0, y = 0, temp, h = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> s;
        
        for (int j = 0; j < m; j++) {
            arr[j] = s[j];
        }

        for (int j = 1; j <= m; j++) {
            temp = arr2[j];

            if (arr[j - 1] == '5') {
                arr2[j] = Min(Min(arr2[j - 1], h), arr2[j]) + 1;

                if (res < arr2[j]) {
                    res = arr2[j];
                    x = i - res + 1;
                    y = j - res + 1;
                } else if (res == arr2[j]) {
                    x = i - res + 1;
                    y = j - res + 1;
                }
            } else {
                arr2[j] = 0;
            }

            h = temp;
        }
    }

    std::cout << res << " " << x << " " << y;
    
    delete[] arr2;
    delete[] arr;
}
