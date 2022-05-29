// This problem is same as median of row, col, sorted matrix
// here k is middle element of matrix;

int bs(int arr[MAX][MAX], int n, int row, int k) {
    int l = 0, h = n - 1, mid;
    while (l <= h) {
        mid = (l + h) >> 1;
        if (arr[row][mid] <= k)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}
int kthSmallest(int mat[MAX][MAX], int n, int k) {
    int c = 0;
    int l = mat[0][0], h = mat[n - 1][n - 1];
    while (l <= h) {
        int mid = (l + h) >> 1;
        c = 0;
        for (int i = 0; i < n; i++) {
            c += bs(mat, n, i, mid);
        }
        if (c < k)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}
// as the min no is starting point of matrix and max is end point of matrix as mat is row and col wise sorted.
// use binary search to find the kth element 
// if there are k elements in left of mid then mid is the kth element
// each time find elements which are less than mid
// if numbers are less than required k then change search space from l -> r to mid+1 -> r