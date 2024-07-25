#include <iostream>
#include <cstdlib>
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

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    mylist *l;
    l=create_list();
    unsigned int n;
    char j;
    int k;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>j;
        if (j =='+')
        {
            cin>>k;
            add(l,k);
        }
        else
        {
            cout<<del_back(l)<<"\n";
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
