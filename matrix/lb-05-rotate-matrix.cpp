void rotateby90(vector<vector<int> >& A, int n) {
    // transpose and reverse
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(A[i][j], A[j][i]);
        }
    }

    // reverse each col
    for (int i = 0; i < n; i++) {
        int l = 0;
        int r = n - 1;
        while (l < r) {
            swap(A[l][i], A[r][i]);
            l++;
            r--;
        }
    }
}