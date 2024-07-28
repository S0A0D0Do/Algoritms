#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graf;
vector<int> TopSort;
vector<bool> visited; 
stack<int> Stack;

void topSortRecursion(int v) {
    visited[v] = true;
    for (int u : graf[v])
    {   if (!visited[u])
            topSortRecursion(u);
    }
    Stack.push(v);
}

void topSort()
{
    visited.assign(n, false); 
    for (int i = 0; i < n; i++)
    {   if (!visited[i])
            topSortRecursion(i);
    }
    reverse(TopSort.begin(), TopSort.end());
}

void dfs(int u) {
    visited[u] = true;
    for (int v : graf[u])
    {   if (!visited[v])
            dfs(v);
    }
    TopSort.push_back(u);
}

int main() {
    int m, x, y;
    cin >> n >> m;
    graf.resize(n + 1);
    visited.resize(n + 1); 
    vector<int> res(n+1);

    for (int i = 0; i < m; ++i)
    {   cin >> x >> y;
        graf[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {   if (!visited[i])
            dfs(i);
    }
    int k;
    for (int i = n-1; i >= 0; --i)
    {  
        k=TopSort[i];
        res[k]=n-i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}

