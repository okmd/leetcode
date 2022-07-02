// compare 2 words of dict to find oder of char
// from order create DAG;
// from DAG find topological sort which is the order of alien dictionary;
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
    }
    void helper(int u, vector<bool>& visited, stack<char>& st) {
        visited[u] = true;
        for (auto v : adj[u]) {
            if (!visited[v]) {
                helper(v, visited, st);
            }
        }
        st.push(u + 'a');
    }
    string findOrder() {
        // find topological sort;
        vector<bool> visited(V, false);
        stack<char> st;
        string ans;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                helper(i, visited, st);
            }
        }
        while (st.size()) {
            ans.push_back(st.top());
            // cout<<st.top()<<";";
            st.pop();
        }
        return ans;
    }
};

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        vector<pair<int, int>> edges;
        for (int i = 0; i < N - 1; i++) {
            string w1 = dict[i];
            string w2 = dict[i + 1];
            // compare char 
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    // w1 is smaller as the words are sorted;
                    edges.push_back({ w1[j] - 'a', w2[j] - 'a' }); // a->b
                    break;
                }
            }
        }
        // now create graph;
        Graph g = Graph(K);
        for (auto edge : edges) {
            g.addEdge(edge.first, edge.second);
        }
        return g.findOrder();
    }
};