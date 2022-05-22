#define ll long long
class Solution {
   public:
    ll int cnt = 0;
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(ll arr[], int l, int m, int r) {
        int i = l;
        int j = m + 1;
        vector<ll int> temp;
        while (i <= m and j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                cnt += m - i + 1;  // for jth element m-1+1 inversions
                // as all the element from i to m are greater than jth element
            }
        }
        while (i <= m) {
            temp.push_back(arr[i++]);
        }
        while (j <= r) {
            temp.push_back(arr[j++]);
        }
        for (int i = l; i < r + 1; i++) {
            arr[i] = temp[i - l];
        }
    }
    void merge_sort(ll arr[], int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
    ll int inversionCount(ll arr[], ll N) {
        merge_sort(arr, 0, N - 1);
        return cnt;
    }
};