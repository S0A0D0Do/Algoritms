#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef struct node node;
struct node {
    int val;
    node *next;
    node *prev;
};

typedef struct {
    int size;
    node *head;
    node *last;
} mylist;

mylist *create_list(){
    mylist *tmp=(mylist *)malloc(sizeof(mylist));
    tmp->head=NULL;
    tmp->last=NULL;
    tmp->size=0;
    return tmp;
}

void add(mylist *l, int a){
    node *new_node=(node *)malloc(sizeof(node));
    new_node->val=a;
    new_node->next=NULL;
    if(l->size==0){
        l->last=new_node;
        l->head=new_node;
        new_node->prev=NULL;
    } else{
        l->last->next=new_node;
        new_node->prev=l->last;
        l->last=new_node;
    }
    l->size+=1;
}

int del(mylist *l)
{
    node *tmp;
    int t;
    tmp=l->head;
    if(l->size==1)
    {
        l->last=NULL;
        l->head=NULL;
    }
    else{
        l->head=l->head->next;
        l->head->prev=NULL;
    }
    l->size-=1;
    t=tmp->val;
    free(tmp);
    return t;
}


int del_back(mylist *l)
{
    node *tmp;
    int t;
    tmp=l->last;
    if(l->size==1)
    {
        l->last=NULL;
         l->head=NULL;
    }
    else{
        ((l->last)->prev)->next=NULL;
        l->last=l->last->prev;
    }
    l->size-=1;
    t=tmp->val;
    free(tmp);
    return t;
}


int Max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else
	return b;
}


int Min(int a, int b)
{
	if (a>b)
	{
		return b;
	}
	else
	return a;
}




int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    mylist *l;
    l=create_list();
    
    unsigned int n,m,j=0,i=0;
    long long int k=0,c1,c2,max1,max2;
    cin>>n>>m;

    for (int i;i<n;++i)
    {
    	if (j<m)
    	{
    		cin>>k;
    		add(l,k);
    		j++;
		}
		else
		{
		cin>>k;
		c1=del(l);
		c2=del_back(l);
		max1=Max(c1,Max(k,c2));
		max2=c1+k+c2-max1-Min(c1,Min(k,c2));
		add(l,max2);
		add(l,max1);
		//cout<<k<<" "<<c1<<" "<<c2<<" "<<max1<<" "<<max2<<endl;
		}
		if (1==m)
    		++j;
    	if (n<m and i==n)
    	{break;
		}
	}
//	if (m>n)
//	{
//		for (int i=j; i<m;++i)
//		{
//			add(l,0);
//		}
//	}
	
	if (m<n)
	{
	
	for (int i=0;i<m;i++)
	{
		cout<<del(l)<<" ";
	}
}
else
{
	for (int i=0;i<n;i++)
	{
		cout<<del(l)<<" ";
	}
}


    
    while (l->head) {
        node *tmp = l->head;
        l->head = l->head->next;
        free(tmp);
    }
    free(l);
    return 0;
}
