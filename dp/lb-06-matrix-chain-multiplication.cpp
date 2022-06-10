int matrixMultiplication(int N, int arr[]) {
  // N-1 matrix multiplication;
  // arr of size N
  vector < vector < int >> dp(N, vector < int > (N, INT_MAX));
  N--;
  for (int d = 0; d < N; d++) {
    for (int i = 0, j = d; j < N; i++, j++) {
      if (d == 0) {
        dp[i][j] = 0; // single element no multiplications
      } else {
        // multiplication between i-j
        for (int k = i; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1]);
        }
      }
    }
  }
  return dp[0][N - 1];
}