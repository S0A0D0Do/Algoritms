#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    a[0]=1;
    a[1]=2;
    
    int k;
    for (int i=2; i<n; i++)
	{
        a[i] = i+1;
        k = a[i/2];
        a[i/2]=a[i];
        a[i]=k;
    }
    
    for (int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
	}
	
    return 0;
}
