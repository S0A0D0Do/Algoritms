#include <iostream>
using namespace std; 

struct Node {
    int index;
    int D;
    Node* next;
    Node* prev;
};

struct mylist {
    Node* t;
    mylist() {
        t = NULL;
    }

    void add(int index, int D) {
        Node* newNode = new Node{ index, D, NULL, t };
        if (t)
            t->next = newNode;
        t = newNode;
    }

    void del() {
        if (t) {
            Node* tmp = t;
            t = t->prev;
            if (t)
                t->next = NULL;
            delete tmp;
        }
    }

    bool empty() { return t == NULL; }

    int Tindex() {
        if (t) return t->index;
        return -1;
    }

    int Tdif() {
        if (t) return t->D;
        return -1;
    }
};

int main() {
    mylist stack;
    int n;
    cin >> n;
    int* dif= new int[n];
    int* res = new int[n];

    for (int i=0; i<n; i++) {
        cin>>dif[i];
        res[i]=-1;

        while (!stack.empty() && dif[i] > stack.Tdif()) {
            int id= stack.Tindex();
            res[id]=i-id;
            stack.del();
        }
        stack.add(i, dif[i]);
    }

    for (int i=0; i<n; i++) 
	cout<<res[i]<<" ";

    delete[] dif;
    delete[] res;
}
