// 1st method
// pick two rows and combine into single row
// repeat till it become 1 row from all rows
// k+k...ktimes = K**2
vector<int> merge(vector<int> &arr1, vector<int> &arr2) {
    // both the vector may not have same length always
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n and j < m) {
        if (arr1[i] < arr2[j]) {
            ans.push_back(arr1[i++]);
        } else {
            ans.push_back(arr2[j++]);
        }
    }
    while (i < n) {
        ans.push_back(arr1[i++]);
    }
    while (j < m) {
        ans.push_back(arr2[j++]);
    }
    return ans;
}
vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    vector<int> ans = arr[0];
    for (int i = 1; i < K; i++) {
        ans = merge(ans, arr[i]);
    }
    return ans;
}

// second method create list and merge the list into single list