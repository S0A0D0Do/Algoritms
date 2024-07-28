#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timer = 0;

void SortPairs(pair<int, int>& a) {
    if (a.first > a.second) {
        swap(a.first, a.second);
    }
}
void dfs(int v, int p, vector<vector<int>>& graf, vector<bool>& visited, vector<int>& tin, vector<int>& fup, vector<pair<int, int>>& bridges) {
    visited[v] = true;
    tin[v] = fup[v] = timer++;
    for (int u : graf[v]) {
        if (u == p) continue;
        if (visited[u])
            fup[v] = min(fup[v], tin[u]);
        else {
            dfs(u, v, graf, visited, tin, fup, bridges);
            fup[v] = min(fup[v], fup[u]);
            if (fup[u] > tin[v]) {
                bridges.push_back({v, u});
            }
        }
    }
}

vector<pair<int, int>> findBridges(int n, vector<vector<int>>& graf) {
    timer = 0;
    vector<bool> visited(n+1, false);
    vector<int> tin(n+1, -1);
    vector<int> fup(n+1, -1);
    vector<pair<int, int>> bridges;

    for (int i = 1; i < n+1; ++i) {
        if (!visited[i]) {
            dfs(i, -1, graf, visited, tin, fup, bridges);
        }
    }
    return bridges;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graf(n+1);
    for (int i = 1; i < m+1; ++i) {
        int a, b,f1=1,f2=1;
        cin >> a >> b;
        for(int j=0;j<graf[a].size();++j)
        {
            if (graf[a][j]==b)
            {
                f1=0;
                graf[a].erase(graf[a].begin()+j);
                break;
            }
        }
        if (f1)
        graf[a].push_back(b);
        for(int j=0;j<graf[b].size();++j)
        {
            if (graf[b][j]==a)
            {
                f2=0;
                graf[b].erase(graf[b].begin()+j);
                break;
            }
        }
        if (f2)
        graf[b].push_back(a);
    }
    vector<pair<int, int>> bridges = findBridges(n, graf);
    for (int i=0;i<bridges.size();++i)
    {
        SortPairs(bridges[i]);
    }
    sort(bridges.begin(),bridges.end());
    for (int i=0;i<bridges.size();++i) {
        cout << bridges[i].first << " " << bridges[i].second << endl;
    }
    return 0;
}
