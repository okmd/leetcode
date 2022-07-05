#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph {
    int V;
    vector<int>* adj;
public:
    Graph(int n) {
        V = n;
        adj = new vector<int>[V];
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void _reverse(vector<int> adjRev[]) {
        vector<bool> present(V, false);
        for (int u = 0; u < V; u++) {
            present[u] = true;
            for (auto v : adj[u]) {
                present[v] = true;
            }
            // make connection to not present;
            for (int i = 0; i < V; i++) {
                if (present[i]) adjRev[u].push_back(i);
            }
            present.clear();
        }
    }
    bool _helper(int u, int col, vector<bool>& path, vector<int>& color) {
        color[u] = col;
        path[u] = true;
        for (auto v : adj[u]) {
            if (!color[v]) {
                if (!_helper(v, 3 - col, path, color)) return false;
            }
            else if (path[v] and col == color[v]) return false;
        }
        path[u] = false;
        return true;
    }
    bool helper(vector<int> adj[], vector<int>& visited, int src) {
        queue<pair<int, int>> q;
        q.push({ src, 0 });  // node and level
        while (q.size()) {
            int curr = q.front().first;
            int level = q.front().second;
            q.pop();
            if (visited[curr] != -1) {
                if (visited[curr] != level) return false;
            }
            else {
                visited[curr] = level;
            }
            for (auto u : adj[curr]) {
                if (visited[u] == -1) {
                    q.push({ u, level + 1 });
                }
            }
        }
        return true;
    }
    // if graph is having more than one componenets
    bool isBipartite1(vector<int> adj[]) {
        vector<int> visited(V, -1);
        for (int i = 0; i < V; i++) {
            if (visited[i] == -1) {
                if (!helper(adj, visited, i)) return false;
            }
        }
        return true;
    }
    bool isBipartite() {
        vector<bool> path(V, false);
        vector<int> color(V, 0);
        vector<int> adjRev[V];
        _reverse(adjRev);
        return isBipartite1(adjRev);
    }
};


int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    int n = mat.size();
    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (mat[i][j])
                g.addEdge(i, j);
        }
    }
    cout << (g.isBipartite() ? "Yes" : "NO") << endl;
    return 0;

}