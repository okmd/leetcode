// Given W and H of a grid
// given n towers and there x,y position
// towers defend the row and col in which they are present.
// find the maximum undefended area
//
#include <algorithm>
#include <cstring>  // for memset
#include <iostream>
#include <vector>
using namespace std;

// NOTE: not considering last width height
int max_undefended_area(int width, int height, vector<pair<int, int>> towers) {
    // grid of size width and height
    int z = 0;
    int grid[width][height] = {0};  // 0=>undefended, 1=>defended
    memset(grid, 0, sizeof(grid));
    for (auto x : towers) {
        for (int i = 0; i < width; i++) {
            grid[i][x.second] = 1;
        }
        for (int i = 0; i < height; i++) {
            grid[x.first][i] = 1;
        }
    }
    // for(int i=0; i<width; i++){
    //     for(int j=0; j<height; j++){
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // find maximum width
    int max_width = 0;
    int prevx = 0;
    // sort by x-coordinate
    sort(towers.begin(), towers.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });

    for (auto x : towers) {
        max_width = max(max_width, abs(x.first - prevx - 1));
        prevx = x.first;
    }
    int prevy = 0;
    int max_height = 0;
    sort(towers.begin(), towers.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    for (auto x : towers) {
        max_height = max(max_height, abs(x.second - prevy - 1));
        prevy = x.second;
    }
    return max_height * max_width;
}

int max_undefended_area2(int width, int height, vector<pair<int, int>> towers) {
    vector<int> x_coordinates;
    vector<int> y_coordinates;
    x_coordinates.push_back(0);
    y_coordinates.push_back(0);
    for (int i = 0; i < towers.size(); i++) {
        x_coordinates.push_back(towers[i].first);
        y_coordinates.push_back(towers[i].second);
    }
    x_coordinates.push_back(width + 1);
    y_coordinates.push_back(height + 1);
    // sort both
    sort(x_coordinates.begin(), x_coordinates.end());
    sort(y_coordinates.begin(), y_coordinates.end());
    int max_width = 0, max_height = 0;
    for (int i = 0; i < x_coordinates.size() - 1; i++) {
        max_width = max(max_width, x_coordinates[i + 1] - x_coordinates[i] - 1);
        max_height = max(max_height, y_coordinates[i + 1] - y_coordinates[i] - 1);
    }
    return max_height * max_width;
}

int main() {
    int w = 15, h = 8, t = 3;
    vector<pair<int, int>> arr;
    int a[] = {3, 11, 8};
    int b[] = {8, 2, 6};
    for (int i = 0; i < t; i++) {
        arr.push_back(make_pair(a[i], b[i]));
    }
    cout << max_undefended_area(w, h, arr) << endl;
    cout << max_undefended_area2(w, h, arr);
    return 0;
}