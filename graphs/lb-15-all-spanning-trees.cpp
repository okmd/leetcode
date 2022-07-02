// Create Adj matrix
// replace diagonal with degree
// replace 1 to -1
// find co-factor of any element
// co-factor = -1^i+jMij
// Mij = remove ith row and jth col
#include <iostream>
#include <vector>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
    vector<int>degree;
public:
    Graph(int n) {
        V = n;
        for (int i = 0;i < V;i++) {
            vector<int>temp;
            for (int j = 0;j < V;j++) {
                temp.push_back(0);
            }
            adj.push_back(temp);
        }
        degree.resize(V, 0);
    }
    void addEdge(int u, int v) {
        adj[v][u] = adj[u][v] = 1;
        degree[u]++;
        degree[v]++;
    }
    int total_msts() {
        // replace diagonal with degree
        for (int i = 0; i < V; i++) {
            adj[i][i] = degree[i];
        }
        // replace 1 -> -1
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i != j and adj[i][j]) {
                    adj[i][j] = -1;
                }
            }
        }
        // find minor @ 0,0
        // generalize for any size matrix;
        return adj[0][0];
    }
};
int main() {
    int V = 5;
    Graph g(V);
    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {0,2}
    };
    for (auto edge : edges) {
        g.addEdge(edge[0], edge[1]);
    }
    cout << g.total_msts();
    return 0;
}