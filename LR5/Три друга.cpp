#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node{
    int data;
    string st;
    node* left=NULL;
    node* right=NULL;
};

node* root = NULL;

node* Ex(node* tmp, string &s)
{
    if (tmp == NULL or s == tmp->st)
        return tmp;
    if (s < tmp->st)
        return Ex(tmp->left, s);
    return Ex(tmp->right, s);
}

node* insert(node* tmp, string &s)
{
    if (tmp == NULL)
    {
        tmp = new node;
        tmp->data = 1;
        tmp->st = s;
        tmp->left = NULL;
        tmp->right = NULL;
    }
    else if (s < tmp->st){
        tmp->left = insert(tmp->left, s);
    }
    else{
        tmp->right = insert(tmp->right, s);
    }
    return tmp;
}


int main()
{
    int n, count= 0;
    cin >> n;
    int a = n*3, bal=n*3;
    vector<string> ar;
    string s;
    
    for (int i = 0; i < n*3; i++){
            cin >> s;
            ar.push_back(s);
            node* newNode = Ex(root, s); 
            if (newNode == NULL)
                root = insert(root, s);
            else
                newNode->data++;
        }
        
     
    
    for (int i = 0; i < a; i++)
    {
        if (count < n)
        {
            node* h = Ex(root, ar[i]);
            if (h->data == 2)
                bal-= 2;
            else if (h->data == 3)
                bal-=3;
            count++;
        }
        
        if (count == n)
        {
            cout << bal <<" ";
            bal = n*3;
            count = 0;
        }
    }
    return 0;
}
