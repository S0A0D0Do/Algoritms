#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int s=0;
vector<vector<int>> graf;
vector<int> ids,low;
vector<bool> onStack;
stack<int> st;
int id = 0,count = 0;

void dfs(int node) {
    st.push(node);
    onStack[node] = true;
    ids[node] = low[node] = id++;
    for (int j : graf[node]) {
        if (ids[j] == -1) {
            dfs(j);
            low[node] = min(low[node], low[j]);
        }
        else if (onStack[j]) 
            low[node] = min(low[node], ids[j]);
    }

    if (ids[node] == low[node]) {
        s++;
        while (true) {
            int cur = st.top();
            st.pop();
            onStack[cur] = false;
            if (cur == node)
                break;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    graf.resize(n + 1);
    ids.resize(n + 1, -1);
    low.resize(n + 1);
    onStack.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b); 
        graf[b].push_back(a); 
    }

    for (int i = 1; i <= n; ++i) {
        if (ids[i] == -1) 
            dfs(i);
    }

    cout << s << endl;

    return 0;
}

