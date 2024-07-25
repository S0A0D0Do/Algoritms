#include <iostream>
using namespace std;

int main()
{
    int n,x,j;
    cin >> n;
    int k[n+1];
    for (int i=0;i<n;i++)
    {
        cin >> k[i];

    }
    for (int i=0; i<n ;i++)
    {
        x = k[i];
		j=i;
		while (j>0 and k[j-1]>x)
        {
            k[j] = k[j-1];  
            --j;
        }
        k[j] = x;
    }
    
    for (int i = 0;i<n;i++)
    {
        cout << k[i] << " ";
    }
}
