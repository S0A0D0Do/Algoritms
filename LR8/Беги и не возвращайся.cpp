#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graf;
vector<bool> visited;

bool dfs(int u, int parent) {
    visited[u] = true;

    for (int v : graf[u])
    {
        if (!visited[v])
        {
            if (dfs(v, u))
                return true;
        }
        else if (v != parent)
            return true;
    }

    return false;
}

bool Cycle() {
    int V = graf.size();
    visited.assign(V, false);

    for (int u = 0; u < V; ++u) {
        if (!visited[u]) {
            if (dfs(u, -1))
                return true;
        }
    }

    return false;
}

int main() {
    int n,m; 
    cin >> n >> m;

    graf.resize(n+1);
    visited.resize(n+1, false);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graf[u].push_back(v);
        graf[v].push_back(u); 
    }

    if (Cycle())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

