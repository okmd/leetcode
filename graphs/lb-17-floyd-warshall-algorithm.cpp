// All pairs shortest path
// foreach v*v-1 paths
// Include each vertex and find path is less then update
// dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
// It can detect -ve edge wt cycle
// Space n^2
// time n*n^2 = n^3
void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (!n) return;
    // change -1 to inf
    int inf = 1000000;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = inf;
            }
        }
    }
    // repeate n-1 time and each time pick a vertex
    for (int k = 0; k < n; k++) {
        // shortest path including kth node
        // do not change kth row and kth col as it will be same
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != k or j != k) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
    // chane back
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == inf) {
                matrix[i][j] = -1;
            }
        }
    }
}