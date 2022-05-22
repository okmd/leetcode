int minSwaps(vector<int>& nums) {
    vector<pair<int, int>> p;
    for (int i = 0; i < nums.size(); i++) {
        p.push_back({nums[i], i});
    }
    sort(p.begin(), p.end());
    int i = 0;
    int count = 0;
    while (i < nums.size()) {
        // if after soring the index is same then current element is at its position. sorted index = unsorted array index
        // if not same then not at its correct position hence needs to be swapped.
        // now find swaps to make original array
        // swap it with its original position.
        if (p[i].second != i) {
            count++;
            swap(p[i], p[p[i].second]);
            // again check if at its required position
            i--;
        }
        i++;
    }
    return count;
}