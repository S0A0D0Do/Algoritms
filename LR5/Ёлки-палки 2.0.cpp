#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    
    node(int value) : data(value), left(NULL), right(NULL) {}
};

void preorder(node* root)
{
    if (root == NULL) 
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node* Tree(vector<int>& arr, int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    node* root = new node(arr[mid]);
    root->left = Tree(arr, start, mid - 1);
    root->right = Tree(arr, mid + 1, end);

    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];

    node* root =Tree(a, 0, a.size() - 1);
    preorder(root);
    
    return 0;
}
