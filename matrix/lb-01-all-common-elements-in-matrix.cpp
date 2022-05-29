#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printCommonElements(vector<vector<int>> &mat) {
    unordered_map<int, int> mp;
    vector<int> ans;
    int current_row = 1;
    // for first row mark each unique element's count 1
    for (int i = 0; i < mat[0].size(); i++) {
        mp[mat[0][i]] = 1;
    }
    // for remaining nodes-> dont add new element as they will not be common
    // but change count, as these elements can be present in all rows
    for (int i = 1; i < mat.size(); i++) {
        current_row = i + 1;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mp[mat[i][j]] + 1 == current_row) {
                mp[mat[i][j]]++;
            }
        }
    }
    for (auto cnt_pair : mp) {
        if (cnt_pair.second == mat.size()) {
            ans.push_back(cnt_pair.first);
        }
    }
    // print ans
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> mat =
        {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };

    printCommonElements(mat);

    return 0;
}