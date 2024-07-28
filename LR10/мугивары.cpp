#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> graph; 
int n, m, k; 

void goodPut(int start, int end) {
    vector<int> dist(graph.size(), INT_MAX);
    vector<bool> visited(graph.size(), false);

    dist[start] = 0;

    for (int i = 0; i < graph.size() - 1; ++i) {
        int minDist = INT_MAX, u = -1;

        for (int j = 1; j < graph.size(); ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int t = edge.second;
            if (!visited[v] && dist[u] + t < dist[v]) {
                dist[v] = dist[u] + t;
            }
        }
    }

    if (dist[end] != INT_MAX)
        cout << dist[end] << endl;
    else
        cout << -1 << endl;
}

int main() {
    cin >> n >> m >> k;

    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        vector<int> I(u);
        for (int j = 0; j < u; ++j)
            cin >> I[j];
        for (int j = 0; j < u; ++j) {
            for (int l = j + 1; l < u; ++l) {
                graph[I[j]].push_back({I[l], v});
                graph[I[l]].push_back({I[j], v});
            }
        }
    }

    goodPut(1, k);

    return 0;
}

