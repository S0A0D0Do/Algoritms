#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graf;
vector<int> low, ids, nodeStack, I;
vector<bool> visited;
int k = 0;
vector<vector<int>> Res;

void dfs(int u) {
    nodeStack.push_back(u);
    visited[u] = true;
    ids[u] = low[u] = ++k;

    for (int v : graf[u]) {
        if (ids[v] == -1)
            dfs(v);
        if (visited[v])
            low[u] = min(low[u], low[v]);
    }

    if (ids[u] == low[u]) {
        vector<int> helps;
        while (true) {
            int node = nodeStack.back();
            nodeStack.pop_back();
            visited[node] = false;
            helps.push_back(node);
            if (node == u) break;
        }
        Res.push_back(helps);
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    graf.resize(n + 1);
    ids.assign(n + 1, -1);
    low.resize(n + 1);
    visited.assign(n + 1, false);
    I.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        graf[start].push_back(end);
    }

    for (int i = 1; i <= n; i++) {
        if (ids[i] == -1)
            dfs(i);
    }

    for (int i = 0; i < Res.size(); i++) {
        for (int node : Res[i])
            I[node] = i;
    }

    for (int i = 0; i < q; ++i) {
        int start, end;
        cin >> start >> end;
        if (I[start] == I[end])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

