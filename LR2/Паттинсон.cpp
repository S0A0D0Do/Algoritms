#include <iostream>
#include <vector>
using namespace std;

void swap(int &c, int &b)
{
    int t = c;
    c = b;
    b = t;
}

void Qsort(vector<int> &a, int s, int e) {
    if(s >= e) 
        return;
      
    int i = s, j = e;
    int mid = a[(s + e) / 2 + 1];
  
    do {
        while(a[i] < mid)
            i++;
        while(a[j] > mid)
            j--;

        if (i <= j) {
            if (i < j)
                swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);

    Qsort(a, s, j);
    Qsort(a, i, e);
}

int main () {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Qsort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
