#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long int a,count=0,b,f1=1,f2=1;
	cin>>a;
	string s;
	cin>>s;
		string s1,s2;
		for (int i=0;i<a/2+a%2;i++)
	{	
		if (s[i]!=s[a-i-1])
		{
			count++;
		}
		if (count>=2)
		{
			cout<<"NO";
			break;
		}
		if (count==1)
		{
			s1=s.substr(0,i)+s.substr(i+1);
			s2=s.substr(0,a-i-1)+s.substr(a-i);
			b=s2.size();
			
			for (int j=0;j<b/2+b%2;++j)
			{
				if (s2[j]!=s2[b-j-1])
				{++count;
				}
				if (count>1){
				f2=0;
				break;}
			}
			
			count=1;
			
			for (int j=0;j<b/2+b%2;++j)
			{
				if (s1[j]!=s1[b-j-1])
				{++count;
				}
				if (count>1){
				f1=0;
				break;}
	
			}
			if (count>=2 and f1+f2==0)
			{
				cout<<"NO";
				break;
			}
			break;
		}
	}
	
	if (count<2 or f1==1 or f2==1)
	{cout<<"YES";
	}
	return 0;	
}
