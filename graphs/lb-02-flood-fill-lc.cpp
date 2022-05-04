void dfs(int i, int j, int m, int n, int c, vector<vector<int>>& image, int ot) {
    if (i < 0 or j < 0 or i >= m or j >= n) return;
    // update only same neighbour value.
    if (image[i][j] == ot) {
        image[i][j] = c;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++)
            dfs(i + dx[k], j + dy[k], m, n, c, image, ot);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size();
    if (m == 0 or image[sr][sc] == newColor) return image;
    int n = image[0].size();
    dfs(sr, sc, m, n, newColor, image, image[sr][sc]);
    return image;
}