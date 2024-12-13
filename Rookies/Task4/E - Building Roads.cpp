#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m;
vector<int> adj[N];
bool visited[N];

void bfs(int start, vector<int>& component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    component.push_back(start);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                component.push_back(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> components;
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            bfs(i, component); 
            components.push_back(component);
        }
    }

    cout << components.size() - 1 << "\n";
    
    for (size_t i = 1; i < components.size(); ++i) {
        cout << components[i-1][0] << " " << components[i][0] << "\n";
    }

    return 0;
}
