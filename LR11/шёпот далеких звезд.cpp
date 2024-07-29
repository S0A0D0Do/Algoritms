#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
struct Edge {
    int from, to, capacity, flow;
};

// Функция для добавления ребра в сеть
void addEdge(vector<vector<int>>& graph, vector<Edge>& edges, int from, int to, int capacity) {
    Edge forward_edge = {from, to, capacity, 0};
    Edge backward_edge = {to, from, 0, 0};
    graph[from].push_back(edges.size());
    edges.push_back(forward_edge);
    graph[to].push_back(edges.size());
    edges.push_back(backward_edge);
}

// Функция для нахождения максимального потока с помощью алгоритма Форда-Фалкерсона
int maxFlow(vector<vector<int>>& graph, vector<Edge>& edges, int source, int sink) {
    int n = graph.size();
    vector<int> parent(n);
    int max_flow = 0;

    while (true) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;
        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int id : graph[cur]) {
                if (parent[edges[id].to] == -1 && edges[id].capacity - edges[id].flow > 0) {
                    parent[edges[id].to] = id;
                    q.push(edges[id].to);
                }
            }
        }

        if (parent[sink] == -1) break;

        int flow = INF;
        for (int u = sink; u != source; u = edges[parent[u]].from) {
            flow = min(flow, edges[parent[u]].capacity - edges[parent[u]].flow);
        }

        for (int u = sink; u != source; u = edges[parent[u]].from) {
            edges[parent[u]].flow += flow;
            edges[parent[u] ^ 1].flow -= flow;
        }

        max_flow += flow;
    }

    return max_flow;
}

int main() {
    int N, M;
    cin >> N >> M;

    int source = 1;
    int sink = N; 

    vector<vector<int>> graph(N + 1);
    vector<Edge> edges;

    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        addEdge(graph, edges, u, v, c);
    }

    int max_tears = maxFlow(graph, edges, source, sink);
    cout <<endl<< max_tears << endl;

    return 0;
}

