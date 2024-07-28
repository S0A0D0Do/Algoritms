#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool compareEdges(const pair<pair<long long int, long long int>, long long int> &a, const pair<pair<long long int, long long int>, long long int> &b) {
    return a.second < b.second;
}

long long int FindP(long long int v, vector<long long int> &p) {
    if (v == p[v])
        return v;
    return p[v] = FindP(p[v], p);
}

void Union(long long int a, long long int b, vector<long long int> &p, vector<long long int> &rootRang) {
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

bool isConnected(long long int n, vector<long long int> p) {
    long long int root = FindP(1, p);
    for (long long int i = 2; i <= n; ++i) {
        if (FindP(i, p) != root)
            return false;
    }
    return true;
}

long long int Kruskal(vector<pair<pair<long long int, long long int>, long long int>> &graf, long long int n) {
    vector<long long int> p(n + 1);
    vector<long long int> rootRang(n + 1, 1);
    sort(graf.begin(), graf.end(), compareEdges);
    for (long long int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    long long int s = 0;
    for (auto e : graf) {
        long long int start = e.first.first, end = e.first.second;
        long long int rootA = FindP(start, p), rootB = FindP(end, p);
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n, m;
    cin >> n >> m;
    vector<pair<pair<long long int, long long int>, long long int>> graf(m);
    for (long long int i = 0; i < m; ++i) {
        cin >> graf[i].first.first >> graf[i].first.second >> graf[i].second;
    }
    long long int res = Kruskal(graf, n);
    cout << res;
    return 0;
}

