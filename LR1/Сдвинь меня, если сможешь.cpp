#include <iostream>
#include <math.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	short a;
	int b,c,d;
	cin>>a>>b;
	b=b%a;
	int k[a*2];
	

if (b>=0)
{
for (int i=0;i<a;i++)
{
	cin>>k[i];
	k[i+a]=k[i];
}

for (int i=a-b;i<(a-b)+a;i++)
{
	cout<<k[i]<<" ";
}
}


if(b<0)
{
	
	for (int i=0;i<a;i++)
{
	cin>>k[i];
	k[i+a]=k[i];
}
b=abs(b);

for (int i=b;i<a+b;i++)
{
	cout<<k[i]<<" ";
}

}

	return 0;
}