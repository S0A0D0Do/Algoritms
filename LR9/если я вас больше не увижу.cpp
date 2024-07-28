#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(int start, vector<vector<pair<int,int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); 
    dist[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (pair<int, int>& edge : graph[u]) { 
            int v = edge.first; 
            int w = edge.second; 
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    int s = INT_MAX;
    for (int i = 1; i < n; ++i)
    { 
        s = dist[i];
    }
    
    if (s == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << s << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
    }
    
    Dijkstra(1, graph);

    return 0;
}

