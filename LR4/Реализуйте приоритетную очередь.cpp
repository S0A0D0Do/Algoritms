#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct object {
    int val;
    int ind;
};

void siftUp(std::vector<object> &a, unsigned long long i) {
    while (i != 0 && a[i].val < a[(i - 1) / 2].val) {
        swap(a[i], a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void siftDown(std::vector<object> &a, int i) {
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

void push(vector<object> &a, int data, int count) {
    object newo{};
    newo.val = data;
    newo.ind = count;
    a.push_back(newo);

    siftUp(a, a.size() - 1);
}

void extractMin(std::vector<object> &a) {
    if (a.empty()) {
        cout << "*\n";
    } else {
        int min = a.front().val;
        a[0] = a[a.size() - 1];
        a.pop_back();
        siftDown(a, 0);

        cout << min << '\n';
    }
}

void decreaseKey(std::vector<object> &a, int x, int y) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].val == x) {
            a[i].val = y;
            siftUp(a, i);
            break;
        }
    }

}

std::vector<object> merge(std::vector<object> &a, std::vector<object> &b){
    std::vector<object> tmp;
    int count=0;
    for(int i=0; i<a.size();++i){
        push(tmp, a[i].val, count);
        count++;
    }
    for(int i=0; i<b.size();++i){
        push(tmp, b[i].val, count);
        count++;
    }
    return tmp;
    
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    std::vector<std::vector <object> > a;
    std::vector<int> count;
    string s;
    while (cin >> s) {
        if(s == "create"){
            std::vector<object> b;
            a.push_back(b);
            count.push_back(0);
        } else if (s == "insert") {
            int x,k;
            cin >>k>> x;

            push(a[k], x, count[k]);
            count[k]++;

        } else if (s == "extract-min") {
            int k;
            cin>>k;
            extractMin(a[k]);
            count[k]++;
        } else if (s == "decrease-key") {
            int x, y,k;
            cin >> k>>x >> y;
            decreaseKey(a[k], x, y);
            count[k]++;

        } else if(s=="merge"){
            int k, x;
			cin>>k>>x;
            std::vector<object> b;
            b = merge(a[k], a[x]);
            a.push_back(b);
            count.push_back(count[k]+count[x]);

        }
    }

    return 0;
}
