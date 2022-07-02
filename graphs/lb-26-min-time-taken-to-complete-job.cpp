#include <iostream>
#include<vector>
#include<stack>
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
        adj[u-1].push_back(v-1);
    }
    void _dfs(int i, int level, vector<int>& visited, stack<pair<int,int>>& st) {
        visited[i] = true;
        for (auto neb : adj[i]) {
            if (!visited[neb]) {
                _dfs(neb, level+1, visited, st);
            }
        }
        st.push({i+1, level});
    }
    void printOrder() {
        stack<pair<int,int>> st;
        vector<int> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                _dfs(i, 1, visited, st);
            }
        }
        while(st.size()){
            cout<<"("<<st.top().first<<", "<<st.top().second<<") ";
            st.pop();
        }
    }
    ~Graph(){
        delete adj;
    }
};
int main() {
    int n;
    n = 10;
    Graph g = Graph(n);

    // Given Directed Edges of graph
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(2, 9);
    g.addEdge(3, 6);
    g.addEdge(4, 6);
    g.addEdge(4, 8);
    g.addEdge(5, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 10);

    // Function Call
    g.printOrder();
    return 0;
}
