
int kdnae(vector<int>& arr) {
    int n = arr.size();
    int curr = 0;
    int mx = INT_MIN;
    for (auto x : arr) {
        curr += x;
        mx = max(mx, curr);
        if (curr < 0) curr = 0;
    }
    return mx;
}
int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    int maximum = INT_MIN;
    for (int k = 0; k < R; k++) {
        vector<int> row(C, 0);
        for (int i = k; i < R; i++) {
            for (int j = 0; j < C; j++) {
                row[j] += M[i][j];
            }
            int maximal = kdnae(row);
            maximum = max(maximum, maximal);
        }
    }
    return maximum;
}
// from 0th row to last row
// from 1st row to lat row
// from last row to last row
// NOTE: add one row above other to make is 1D to apply kdane;
// Each possible rectangle is formed; from 1x1 to nxn.