#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<pair<pair<int,int>,int>> graf;
int mA;
set<int>y;
set<pair<int, vector<int>>> foundMSTs;

bool compareEdges(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b) {
    return a.second < b.second;
}

int FindP(int v, vector<int> &p) {
    if (v == p[v])
        return v;
    return p[v] = FindP(p[v], p);
}

void Union(int a, int b, vector<int> &p, vector<int> &rootRang) {
    a = FindP(a, p);
    b = FindP(b, p);
    if (a != b) {
        if (rootRang[a] < rootRang[b])
            swap(a, b);
        p[b] = a;
        if (rootRang[a] == rootRang[b])
            rootRang[a]++;
    }
}

bool isConnected(int n, vector<int> p) {
    int root = FindP(1, p);
    for (int i = 2; i <= n; ++i) {
        if (FindP(i, p) != root)
            return false;
    }
    return true;
}

int Kruskal(int n, int m) {
    vector<int> p(n + 1);
    vector<int> rootRang(n + 1, 1);
    sort(graf.begin(), graf.end(), compareEdges);
    
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    
    int s = 0;
    int mC=1000;
    for (int i=0;i<m;++i) {
        pair<pair<int,int>,int> e=graf[i];
        int start = e.first.first, end = e.first.second;
        int rootA = FindP(start, p), rootB = FindP(end, p);
        if (rootA != rootB) {
            s += e.second;
            if(mC>e.second)
            {
                mA=i;
            }
            Union(rootA, rootB, p, rootRang);
        }
    }
    
    if (isConnected(n, p))
    {
        foundMSTs.insert({s, p});
        return s;
    }
    else
        return -1;
}

void FindAllMST(int n, int m) {
    vector<pair<pair<int, int>, int>> remainingEdges(m);

    
    for (int i = 0; i < m; ++i) {
        if (i != mA)
        {
            remainingEdges.push_back(graf[i]);
        }
    }
    vector<int> p(n + 1);
    vector<int> rootRang(n + 1, 1);
    for (auto newEdge : remainingEdges) {
        int totalWeight = 0;

        for (int i = 1; i <= n; ++i)
            p[i] = i;

        for (auto e : graf) {
            int start = e.first.first, end = e.first.second;
            int rootA = FindP(start, p), rootB = FindP(end, p);
            if (e != newEdge && rootA != rootB) {
                totalWeight += e.second;
                Union(rootA, rootB, p, rootRang);
            }
        }

        if (isConnected(n, p)) {
            y.insert(totalWeight);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    graf.resize(m);
    
    int mA, mB, mC = 1000000;
    for (int i = 0; i < m; ++i)
    {
        cin >> graf[i].first.first >> graf[i].first.second >> graf[i].second;
    }

    int res = Kruskal(n,m);

    FindAllMST(n,m);
    int c=0;
    for(auto i : y)
    {
        if (c<2)
    {cout << i << " ";
        c++;
    }}

    return 0;
}

