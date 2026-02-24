#include <vector>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>> &adj,
            vector<bool> &visited, int s, vector<int> &res) {

    visited[s] = true;
    res.push_back(s);

    for (int i : adj[s]) {
        if (!visited[i]) dfs(adj, visited, i, res);
    }
}


int main() {
    int nyan, meow;
    cin >> nyan >> meow;

    vector<vector<int>> G(nyan);

    for (int i = 0; i < meow; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> visited(G.size(), false);
    int n_components = 0;

    for (int i = 0; i < (int)G.size(); i++) {
        if (!visited[i]) {
            vector<int> res;          // nodes in this component
            dfs(G, visited, i, res);  // explore it
            n_components++;
        }
    }

   
