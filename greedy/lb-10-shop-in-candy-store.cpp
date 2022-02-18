// Given n numbers of different candies
// and you are given k free candies when you buy a candie
// price of each candies are also given
// You need to find minimum and maxumum amount of money needed to buy all candies
// IDEA: when you want to buy all different candies in minimum amount
// buy the least priced candy and take most priced candies from free.
int min_amount_needed(int arr[], int k, int n) {
    sort(arr, arr + n);
    int i = 0;
    int j = n - 1;
    int amt = 0;
    while (i <= j) {
        amt += arr[i++];
        j -= k;
    }
    return amt;
}

// IDEA: when you want to buy all different candies in maximum amount
// buy the most priced candy and take least priced candies from free.
int max_amount_needed(int arr[], int k, int n) {
    sort(arr, arr + n, [](int a, int b) {
        return a > b;
    });
    int i = 0;
    int j = n - 1;
    int amt = 0;
    while (i <= j) {
        amt += arr[i++];
        j -= k;
    }
    return amt;
}
vector<int> combined(int arr[], int k, int n) {
    sort(arr, arr + n);
    int i = 0, j = n - 1, mn_amt = 0, mx_amt = 0;
    while (i <= j) {
        mn_amt += arr[i++];
        j -= k;
    }
    i = 0, j = n - 1;
    while (i <= j) {
        mx_amt += arr[j--];
        i += k;
    }
    vector<int> ans = {mn_amt, mx_amt};
    return ans;
}