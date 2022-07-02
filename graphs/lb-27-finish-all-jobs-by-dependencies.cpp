#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Graph {
    int V;
    vector<int>* adj;
public:
    Graph(int v) {
        V = v;
        adj = new vector<int>[V];
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    bool helper(int u, vector<bool>& visited, vector<bool>& path) {
        visited[u] = path[u] = true;
        for (auto v : adj[u]) {
            if (!visited[v]) {
                if (helper(v, visited, path)) return true;
            }
            else if (path[v]) return true;
        }
        return path[u] = false;
    }
    bool cyclic() {
        vector<bool> visited(V, false), path(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (helper(i, visited, path)) return true;
            }
        }
        return false;
    }
    bool canComplete() {
        // If acyclic directed graph then topological sort can be found;
        // topological order can be the order of compelition of dependency;
        if (cyclic()) return false;
        return true;
    }
};
int main() {
    int n = 4;
    vector<pair<int, int>> preq = { {1,0}, {2,1},{3,2} };
    Graph g = Graph(n);
    for (auto v : preq) {
        g.addEdge(v.first, v.second);
    }
    cout << g.canComplete();
    return 0;
}