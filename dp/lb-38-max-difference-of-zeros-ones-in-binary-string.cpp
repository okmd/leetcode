int maxSubstring(string S) {
    // this problem is extension of kdane's algorithm
    // replace 0-1 and 1->-1
    // max-subset sum will be 0's - 1's
    vector<int> arr;
    for (int i = 0; i < S.size(); i++) {
        arr.push_back((S[i] == '1') ? -1 : 1);
    }
    int curr_sum = arr[0];
    int max_sum = arr[0];
    for (int i = 1; i < S.size(); i++) {
        if (curr_sum < 0) {
            curr_sum = arr[i];
        } else {
            curr_sum += arr[i];
        }
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}