// Minimum numbers of colors required to color the complete graph (chromatic numbers).
bool colorable(bool graph[101][101], int n, int col, int color[], int curr) {
    // can curr be colored with col
    for (int i = 0; i < n; i++) {
        // if curr;s adjacent node already colored with col
        if (i != curr and graph[i][curr] and color[i] == col) return false;
    }
    return true;
}
bool helper(bool graph[101][101], int n, int m, int color[], int curr) {
    // current node is the last node, successfully colored all nodes
    if (curr == n) return true;
    for (int col = 1; col <= m; col++) {
        if (colorable(graph, n, col, color, curr)) {
            color[curr] = col;
            if (helper(graph, n, m, color, curr + 1)) return true;
            color[curr] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n] = {0};
    return helper(graph, n, m, color, 0);
}