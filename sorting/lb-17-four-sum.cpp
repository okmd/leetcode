vector<vector<int>> fourSum(vector<int> &arr, int sm) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    set<vector<int>> sv;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int req = sm - (arr[i] + arr[j] + arr[k]);
                if (binary_search(arr.begin() + k + 1, arr.end(), req)) {
                    vector<int> v = {arr[i], arr[j], arr[k], req};
                    sort(v.begin(), v.end());
                    sv.insert(v);
                }
            }
        }
    }
    // from set to vector
    vector<vector<int>> ans{sv.begin(), sv.end()};
    return ans;
}
// optimize
vector<vector<int>> fourSum(vector<int> &arr, int sm) {
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int req = sm - (arr[i] + arr[j]);
            // use two pointer to search req sum
            int l = j + 1;
            int r = n - 1;
            while (l < r) {
                int two_sm = arr[l] + arr[r];
                if (two_sm == req) {
                    vector<int> quad = {arr[i], arr[j], arr[l], arr[r]};
                    ans.push_back(quad);
                    // remove same for two pointers
                    while (l < r and arr[l] == quad[2]) l++;
                    while (l < r and arr[r] == quad[3]) r--;
                } else if (two_sm < req)
                    l++;
                else
                    r--;
            }
            // remoe same element for j
            while (j + 1 < n and arr[j] == arr[j + 1]) j++;
        }
        while (i + 1 < n and arr[i] == arr[i + 1]) i++;
    }
    return ans;
}