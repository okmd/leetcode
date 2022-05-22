// LC
int count(int a) {
    int c = 0;
    while (a) {
        c += (a & 1);
        a >>= 1;
    }
    return c;
}
vector<int> sortByBits(vector<int> arr) {
    stable_sort(arr.begin(), arr.end(), [&](int a, int b) {
        // if count is same then ascending order of numbers
        // else ascending order of count.
        int c = count(a);
        int d = count(b);
        return (c == d) ? a < b : c < d;
    });
    return arr;
}

// GFG
int count(int a) {
    int c = 0;
    while (a) {
        c += a & 1;
        a >>= 1;
    }
    return c;
}
void sortBySetBitCount(int arr[], int n) {
    stable_sort(arr, arr + n, [&](int a, int b) {
        int c = count(a);
        int d = count(b);
        return c > d;
    });
}