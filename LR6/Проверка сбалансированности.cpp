#include <iostream>
#include <cmath>
using namespace std;

struct node {
    int data,cl,cr,res;
    node* left;
    node* right;
    node* parent;
};

node* createNode(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->cl = 0;
    newNode->cr = 0;
    newNode->res = 0;
    newNode->parent = NULL;
    return newNode;
}

int Max(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main() {
    int n, k, l, r;
    cin >> n;
    node* a[n];
    for (int i = 0; i < n; i++) {
        a[i] = createNode(0);
    }
    for (int i = 0; i < n; i++) {
        cin >> k >> l >> r;
        a[i]->data = k;
        if (l > 0) {
            a[i]->left = a[l - 1];
            a[l - 1]->parent = a[i];
            a[i]->cl+=a[l-1]->res;
            
        }
        if (r > 0) {
            a[i]->right = a[r - 1];
            a[r - 1]->parent = a[i];
			a[i]->cr+=a[r-1]->res;
        }
        a[i]->res=Max(a[i]->cr,a[i]->cl);
        if (l==0 )
        {
        	a[i]->cl=1;
		}
		if (r==0)
		{
			a[i]->cr=1;
		}
		//cout<<" "<<a[i]->data<<" "<<a[i]->left<<" "<<a[i]->right<<" "<<a[i]->res<<endl;
        
    }
  
    for (int i=0;i<n;i++)
    {
    	if (a[n-1-i]->left)
    	{
    		a[n-1-i]->cl=a[n-1-i]->left->res+1;
    		//cout<<" left"<<a[n-1-i]->left->data<<" "<<a[n-1-i]->left->res<<endl;
		}
	
		if (a[n-1-i]->right)
    	{
    		a[n-1-i]->cr=a[n-1-i]->right->res+1;
    		//cout<<" right "<<a[n-1-i]->right->data<<" "<<a[n-1-i]->right->res<<endl;
		}
		
    	a[n-1-i]->res=Max(a[n-1-i]->cl,a[n-1-i]->cr);
		//a[i]->res=Max(a[i]->cr,Max(a[i]->cl,a[i]->res));
	}
	for (int i=0;i<n;i++)
	{
		cout<<a[i]->cr-a[i]->cl<<endl;
	}
    return 0;
}

