#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node{
    int data;
    struct node *l;
    struct node *r;
};

struct node* root = NULL;

node* next(node* root, int data) {
    if (root == NULL)
        return NULL;
    if (data >= root->data)
        return next(root->r, data);
    node* left = next(root->l, data);
    return (left != NULL) ? left : root;
}

node* prev(node* root, int data) {
    if (root == NULL)
        return NULL;
    if (data <= root->data)
        return prev(root->l, data);
    node* right = prev(root->r, data);
    return (right != NULL) ? right : root;
}

node* prev(int x)
{
    node* tmp = root;
    node* res = NULL;
    while (tmp != NULL) {
        if (tmp->data < x)
        {
            res = tmp;
            tmp = tmp->r;
        }
        
        else
            tmp = tmp->l;
    }
    return res;
}

bool Ex(node* root, int x )
{
    if (root == NULL)
        return false;
        
    if(root->data == x)
        return true;
        
    else if (x < root->data)
        return Ex(root->l, x);
        
    else if( x > root->data )
        return Ex(root->r, x);
}

node* insert(node* root, int x)
{
    if (Ex(root, x))
        return root;
        
    if(root==NULL)
    {
        node* new_node = new node;
        new_node->data = x;
        new_node->l = NULL;
        new_node->r = NULL;
        return new_node;
    }
        
    else
    {
        if(x < root->data)
            root->l = insert(root->l,x);
            
        else
            root->r = insert(root->r,x);
            
        return root;
    }
}

node* find_min(node* root)
{
    while(root->l != NULL)
        root = root->l;
    return root;
}

node* del(node *root, int x){

    if(root == NULL)
        return root;
      
    else if(x < root->data) 
        root->l = del(root->l,x);
      
    else if (x > root->data) 
        root->r = del(root->r, x);
      
    else {
        if(root->l == NULL && root->r == NULL)
            root = NULL;

        else if(root->l == NULL) {
            struct node *temp = root;
            root = root->r;
            delete temp;
        }
        
        else if(root->r == NULL) {
            struct node *tem = root;
            root = root->l;
            delete tem;
        }
        
        else {
            struct node *temp = find_min(root->r);
            root->data = temp->data;
            root->r = del(root->r, temp->data);
        }
    }
    return root;
}


int main()
{
    string s;
    int x,i=0;
    while (cin>>s and i<100)
    {
        i++;
        if (s == "insert")
        {
            cin>>x ;
            if (!Ex(root, x))
                root = insert(root, x);
        }
        
        else if (s == "exists")
        {
            cin>>x;
            if (Ex(root, x))
                cout<< "true"<<endl;
                
            else
                cout<<"false"<<endl;
        }
        
        else if (s == "delete")
        {
            cin>>x;
            root = del(root, x);
        }
        
        else if (s == "prev")
        {
            cin>>x;
            if (prev(x) == NULL)
                cout<<"none"<<endl;
                
            else
            {
                node* res = prev(root, x);
                cout<<res->data<<endl;
            }
        }
        else if (s=="next")
        {
            cin>>x;
            if (next(root, x)==NULL)
                cout<<"none"<<endl;
            
            else
            {
                node* res = next(root, x);
                cout<<res->data<<endl;  
            }
        }
    }
    return 0;
}
