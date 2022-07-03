#include<iostream>
#include<vector>
#include<set>
#include<stack>
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
    bool dfs(int u, int v, stack<int>& path, vector<bool>& visited) {
        visited[u] = true;
        path.push(u);
        if (u == v) {
            visited[u] = false;
            return true;
        }
        for (int i : adj[u]) {
            if (!visited[i])
                if (dfs(i, v, path, visited)) return true;
        }
        path.pop();
        visited[u] = false;
        return false;
    }
    void find_path(int u, int v, string C, set<string>& ans) {
        stack<int> path;
        vector<bool>visited(V, false);
        path.push(u);
        visited[u] = true;
        for (int i : adj[u]) {
            if (!visited[i])
                if (dfs(i, v, path, visited)) break;
        }
        string temp;
        while (path.size()) {
            // cout<<path.top()<<" ";
            temp.push_back(C[path.top()]);
            path.pop();
        }
        // cout<<endl;
        ans.insert(temp);
    }
};

int solve(int A, vector<vector<int> >& B, string C, vector<vector<int> >& D) {
    Graph g(A);
    set<string> ans;
    for (auto edge : B) {
        g.addEdge(edge[0] - 1, edge[1] - 1);
    }
    for (auto q : D) {
        g.find_path(q[0] - 1, q[1] - 1, C, ans);
    }
    // for(auto s:ans){
    //     cout<<s<<" ";
    // }
    return ans.size();

}
int main() {
    int n, q;
    cin >> n;
    vector<vector<int>> edges(n - 1, vector<int>(2, 0));
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2, 0));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    string s;
    cin >> s;
    cout << solve(n, edges, s, queries) << endl;
    return 0;
}
/*
5
1 4
5 1
2 4
3 4
2
5 2
3 5
baaba
ANS:1
////////////////
5
1 2
2 3
3 4
4 5
4
1 3
3 5
2 3
2 1
ababa
ANS:2
// https://leetcode.com/playground/dRmNJFye
*/