#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct worker {
    int val;
    int ind;
};


void siftDown(vector<worker> &a, int i) {
    while (2 * i + 1 < a.size()) {
        int l = 2*i+1;
        int r = 2*i+2;

        int j=l;
        if (r < a.size() && a[r].val < a[l].val) {
            j = r;
        }
        if (a[i].val <= a[j].val) {
            break;
        }
        swap(a[i], a[j]);
        i = j;
    }
}
int extractMin(vector<worker> &a) {
        int min = a.front().val;
        a[0] = a[a.size() - 1];
        a.pop_back();
        siftDown(a, 0);

        return min ;
}

void siftUp(vector<worker> &a, unsigned long long i) {
    while (i != 0 && a[i].val < a[(i - 1) / 2].val) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void push(vector<worker> &a, int data, int count) {
    worker newo{};
    newo.val = data;
    newo.ind = count;
    a.push_back(newo);
    siftUp(a, a.size() - 1);
}


void siftDownIND(vector<worker> &a, int i) {
    while (2 * i + 1 < a.size()) {
        int l = 2*i+1;
        int r = 2*i+2;

        int j=l;
        if (r < a.size() && a[r].ind < a[l].ind) {
            j = r;
        }
        if (a[i].ind <= a[j].ind) {
            break;
        }
        swap(a[i], a[j]);
        i = j;
    }
}
int extractMinIND(vector<worker> &a) {
        int min = a.front().val;
        a[0] = a[a.size() - 1];
        a.pop_back();
        siftDownIND(a, 0);

        return min ;
}

void siftUpIND(vector<worker> &a, unsigned long long i) {
    while (i != 0 && a[i].ind < a[(i - 1) / 2].ind) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void pushIND(vector<worker> &a, int data, int count) {
    worker newo{};
    newo.val = data;
    newo.ind = count;
    a.push_back(newo);
    siftUpIND(a, a.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<worker> a;
    long long int x, m, o, t, f;
    unsigned long long n, nj;
    cin >> n >> m;
    worker h;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(a,x,0);
    }
    
//    for (int i=0;i<n;i++)
//    {
//    	cout<<i<<" "<< a.front().val <<endl;
//    	a.erase(a.begin());
//	}
    
    vector<worker> j;
    long long int s = 0, work;
    nj = j.size();
    n = a.size();

    for (int i = 0; i < m; i++) {
        cin >> t >> f;
        
        while (nj > 0 && t >= j.front().ind) {
            x = extractMinIND(j); 
            nj=j.size();
            push(a,x,0);
            n=a.size();
        }
        if (n > 0) {
        	x=extractMin(a);
            s += x * f;
            n=a.size();
            pushIND(j,x,t+f);
           
            nj=j.size();
        }
        
    }

    cout << s;

    return 0;
}
