#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Min( int a, int b, int c)
{
    if (a<=b and a<=c)
    return a;
    if (b<=a and b<=c)
    return b;
    return c;
    
}

int main() {
    int n, m;
    cin>>n>>m;

    string* arr = new string[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int res = 0;
    int x = 0, y = 0;

    int** mas = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        mas[i] = new int[m + 1];
    }

    for (int i =n-1; i >= 0; i--) {
        for (int j =m-1; j >= 0; j--) {
            if (arr[i][j] == '5') {
                mas[i][j] = Min(mas[i + 1][j], mas[i][j + 1], mas[i + 1][j + 1]) + 1;
                if (mas[i][j] >res) {
                    res =mas[i][j];
                    x = i + 1;
                    y = j + 1;
                }
            }
        }
    }

    cout<<res<<" "<<x<<" "<<y;

    delete[] arr;

    for (int i = 0; i <= n; ++i) {
        delete[] mas[i];
    }
    delete[] mas;

    return 0;
}
