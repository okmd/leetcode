
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef tuple<int, int, int> triplet;
class UBR {
    int n;
    vector<int> parent, rank;
public:
    UBR(int n) {
        parent.resize(n, -1);
        rank.resize(n, -1);
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int u, int v) {
        int s1 = find(u);
        int s2 = find(v);
        if (s1 != s2) {
            if (rank[s1] > rank[s2]) {
                swap(s1, s2);
            }
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
    }
};

int mst(int n, vector<triplet> edges) {
    sort(edges.begin(), edges.end(), [](triplet a, triplet b) {
        return get<2>(a) < get<2>(b);
    });
    UBR s(n);
    int ans=0;
    for (auto [u, v, w] : edges) {
        if (s.find(u) != s.find(v)) {
            s.unite(u, v);
            ans += w;
            cout << "(" << u << "," << v << "," << w << ") ";
        }
    }
    return ans;
}
int main(){
    vector<triplet> edges = {
      {0, 1, 10},
      {1, 3, 15},
      {2, 3, 4},
      {2, 0, 6}, 
      {0, 3, 5} 
    };
    cout<<mst(edges.size(), edges);
    return 0;
}

// https://leetcode.com/playground/fUGQrtsS