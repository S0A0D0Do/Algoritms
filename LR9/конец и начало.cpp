#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> graf;
vector<bool> visited;
queue<int> Q;

void bfs(int v) {
    Q.push(v);
    visited[v] = true;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int nxt : graf[u]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                Q.push(nxt);
            }
        }
    }
}

int main() {
    int n, m, a, b, q;
    cin >> n >> m >> q;
    graf.resize(n + 1);
     visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    char t;
    
    for (int i = 1; i <= q; ++i) {
        cin >> t >> a >> b;

        if (t == '?') {
            visited.assign(n + 1, false);
            if (a==b)
            cout<<"YES"<<endl;
            else{
            bfs(a);
            if (visited[b])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            }
        } 
        
        else
        {
            for (int j = 0; j < graf[a].size(); ++j) {
                if (graf[a][j] == b)
                {
                    graf[a].erase(graf[a].begin() + j);
                    break;
                }
            }

            for (int j = 0; j < graf[b].size(); ++j)
            {
                if (graf[b][j] == a)
                {
                    graf[b].erase(graf[b].begin() + j);
                    break;
                }
            }
        }
    }

    return 0;
}

