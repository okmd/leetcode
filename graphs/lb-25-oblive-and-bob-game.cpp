#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int> adj[], vector<int> &inTime, vector<int> &outTime, int &timer, int src, int parent) {
    inTime[src] = timer++;
    for (auto v : adj[src]) {
        if (v != parent) {
            dfs(adj, inTime, outTime, timer, v, src);
        }
    }
    outTime[src] = timer++;
    cout << "(" << src << " " << inTime[src] << " " << outTime[src] << ");";
}
bool is_subtree(vector<int> adj[], vector<int> &inTime, vector<int> &outTime, int x, int y) {
    // parent intime will be less and outtime will be more
    // checking is y is parent of x
    return (inTime[x] > inTime[y] and outTime[x] < outTime[y]);
}

bool can_find(vector<int> adj[], vector<int> &inTime, vector<int> &outTime, int dir, int x, int y) {
    // @x olive is hiding
    // @y bob is finding olive
    // dir, bob moving, 0(towards Mansion), 1(away from mansion).
    if (!is_subtree(adj, inTime, outTime, x, y) and !is_subtree(adj, inTime, outTime, y, x)) return false;
    // move away from manshion
    if (!dir) {
        return is_subtree(adj, inTime, outTime, y, x);
    }
    return is_subtree(adj, inTime, outTime, x, y);
}
int main() {
    // fast io
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int timer = 0;
    vector<int> inTime(n, 0), outTime(n, 0);
    // use dfs to assign entry and exit time of each node
    dfs(adj, inTime, outTime, timer, 0, -1);
    int q;
    cin >> q;
    while (q--) {
        int dir, x, y;
        cin >> dir >> x >> y;
        if (can_find(adj, inTime, outTime, dir, x - 1, y - 1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}