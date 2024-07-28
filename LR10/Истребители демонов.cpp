#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool compareEdges(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
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

int Kruskal(vector<pair<pair<int, int>, int>> &graf, int n) {
    vector<int> p(n + 1);
    vector<int> rootRang(n + 1, 1);
    sort(graf.begin(), graf.end(), compareEdges);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    int s = 0;
    for (auto e : graf) {
        int start = e.first.first, end = e.first.second;
        int rootA = FindP(start, p), rootB = FindP(end, p);
        if (rootA != rootB) {
            s += e.second;
            Union(rootA, rootB, p, rootRang);
        }
    }
    if (isConnected(n, p))
        return s;
    else
        return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> graf(m);
    for (int i = 0; i < m; ++i) {
        cin >> graf[i].first.first >> graf[i].first.second >> graf[i].second;
    }
    int res = Kruskal(graf, n);
    cout << res;
    return 0;
}
