#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int main() {
	
	long long a,b,m;
	cin>>a>>b;
	
	if (a==0 or b==0)
	{
		cout<<"0";
	}
	else
	 cout<<gcd(a,b);
	return 0;
}
