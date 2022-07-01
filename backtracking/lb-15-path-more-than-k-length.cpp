// from source node to destination node atleat k distance should be there;
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int>edge;
class Graph {
    int V;
    vector<edge>* adj;
    bool helper(int u, int k, vector<bool>& path) {
        if (k <= 0) return true;
        for (auto [v, w] : adj[u]) {
            if (path[v]) continue; // if current node exits in path i.e hence cycle; so ignore this path;
            if (w >= k) return true; // if curr edge weight is more than k hence it itself make path more than k hence return true;
            path[v] = true; // take this node in path
            if (helper(v, k - w, path)) return true; // remove w from requrired k;
            path[v] = false; // if including this node not found path hence make it false and try next node;
        }
        // if any of the adjacent node of u did not find path >= k hence return false;
        return false;
    }
public:

    Graph(int v) {
        V = v;
        adj = new vector<edge>[V];
    }
    void addEdge(int u, int v, int w) {
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    bool pathMoreThanK(int u, int k) {
        vector<bool> path(V, false);
        path[u] = 1;
        return helper(u, k, path);
    }
};
int main() {
    // create the graph given in above figure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 62;
    cout << (g.pathMoreThanK(src, k) ? "Yes\n" : "No\n");

    k = 60;
    cout << (g.pathMoreThanK(src, k) ? "Yes\n" : "No\n");
    return 0;
}
// https://leetcode.com/playground/LbdfKDz5