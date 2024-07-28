#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> p;
vector<int> h;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (h[x] < h[y]) {
        p[x] = y;
    }
    else {
        p[y] = x;
        if (h[x] == h[y]) {
            h[x]++;
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    h.resize(n+1, 1);
    p.resize(n+1);
    for (int i = 0; i < n; i++) 
        p[i] = i;
    
    vector<set<int>> g(n+1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    
    vector<pair<char, pair<int, int>>> queries(q);
    
    for (int i = 0; i < q; i++) {
        char op;
        int a, b;
        cin >> op >> a >> b;

        
        queries[i] = {op, {a, b}};
        if (op == '-') {
            g[a].erase(b);
            g[b].erase(a);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (auto e : g[i]) {
            if (find(i) != find(e)) {
                unite(i, e);
            }
        }
    }
    
    vector<string> ans(q);
    
    for (int i = q - 1; i >= 0; i--) {
        char op = queries[i].first;
        int a = queries[i].second.first, b = queries[i].second.second;
        
        if (op == '?') {
            if (find(a) == find(b)) {
                ans[i] = "YES";
            }
            else {
                ans[i] = "NO";
            }
        } else {
            if (find(a) != find(b)) {
                unite(a, b);
            }
        }
    }
        
    for (auto e : ans) 
    if (e!="")
    cout << e << "\n";
    
    return 0;
}
