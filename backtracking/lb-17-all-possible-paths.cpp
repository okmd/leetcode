#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
vector<vector<int>>paths;
bool safe(vector<vector<int>>& mat, int i, int j) {
    int n = mat.size();
    int m = mat[0].size();
    return (i < n and j < m and i >= 0 and j >= 0 and mat[i][j] != -1);
}
void findPaths(vector<vector<int>>& mat, int i, int j, vector<int>& path) {
    if (i == mat.size() - 1 and j == mat[0].size() - 1) {
        path.push_back(mat[i][j]);
        paths.push_back(path);
        path.pop_back();
        return;
    }
    if (!safe(mat, i, j)) return;

    int orig = mat[i][j];
    path.push_back(orig);
    mat[i][j] = -1;
    for (int k = 0; k < 2; k++) {
        int p = i + dx[k], q = j + dy[k];
        findPaths(mat, p, q, path);
    }
    mat[i][j] = orig;
    path.pop_back();

}
// using Queue
class cell {
public:
    int i, j;
    vector<int> path;
    cell(vector<int> p, int x, int y) {
        path=p;
        i = x;
        j = y;
    }
};

void findPaths(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>ans;
    queue<cell> q;
    q.push({ {mat[0][0]}, 0,0 });
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(p.i==n-1 and p.j==m-1){
            paths.push_back(p.path);
        }
        for (int k = 0; k < 2; k++) {
            int x = p.i + dx[k], y = p.j + dy[k];
            if(safe(mat, x, y)){
                vector<int>temp= p.path;
                temp.push_back(mat[x][y]);
                q.push({temp,x,y});
                temp.pop_back();
            }
        }
    }
}
int main() {
    // input matrix with hurdles shown with number 0
    vector<vector<int>> mat = {
        {1,2,3},{4,5,6},{7,8,9}
    };
    // find longest path with source (0, 0) and
    // destination (1, 7)
    int i = 0, j = 0;
    vector<int> path;
    findPaths(mat, i, j, path);
    findPaths(mat);

    for (auto path : paths) {
        for (auto val : path)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
// https://leetcode.com/playground/QDwD9r84