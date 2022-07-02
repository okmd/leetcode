#include <iostream>
#include<vector>
#include<stack>
#include<queue>
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
    void _dfs(int i, int level, vector<int>& visited, stack<pair<int, int>>& st) {
        visited[i] = true;
        for (auto neb : adj[i]) {
            if (!visited[neb]) {
                _dfs(neb, level + 1, visited, st);
            }
        }
        st.push({ i, level });
    }
    void printOrder(vector<int>& ans) {
        stack<pair<int, int>> st;
        vector<int> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                _dfs(i, 1, visited, st);
            }
        }
        while (st.size()) {
            cout << "(" << st.top().first << ", " << st.top().second << ") ";
            ans[st.top().first]=st.top().second;
            st.pop();
        }
    }
    void printOrder1(vector<int>& ans) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto v : adj[i])
                indegree[v]++;
        }

        queue<int> q;
        // push all elements with indegree 0
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0) q.push(i);
        int count = 0;
        while (q.size()) {
            int m = q.size();
            count++;
            while (m--) {
                int p = q.front();
                q.pop();
                ans[p] = count;
                // remove adjacent indegree
                for (auto id : adj[p]) {
                    indegree[id]--;
                    if (!indegree[id]) q.push(id);
                }
            }

        }
    }
    ~Graph() {
        delete adj;
    }
};
int main() {
    int n;
    n = 10;
    Graph g = Graph(n);

    // Given Directed Edges of graph
    g.addEdge(1-1, 3-1);
    g.addEdge(1-1, 4-1);
    g.addEdge(1-1, 5-1);
    g.addEdge(2-1, 3-1);
    g.addEdge(2-1, 8-1);
    g.addEdge(2-1, 9-1);
    g.addEdge(3-1, 6-1);
    g.addEdge(4-1, 6-1);
    g.addEdge(4-1, 8-1);
    g.addEdge(5-1, 8-1);
    g.addEdge(6-1, 7-1);
    g.addEdge(7-1, 8-1);
    g.addEdge(8-1, 10-1);

    // Function Call
    vector<int>ans(n);
    g.printOrder(ans);
    for (auto s : ans) {
        cout << s << " ";
    }
    g.printOrder1(ans);
    for (auto s : ans) {
        cout << s << " ";
    }
    return 0;
}
