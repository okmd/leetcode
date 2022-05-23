int count(int n) {
    int prod = 5;
    int ans = 0;
    while (n >= prod) {
        ans += n / prod;
        prod *= 5;
    }
    return ans;
}
int findNum(int n) {
    // as 5*n will contains alteast n fives hence is is guranteed that
    // from 1 to 5*n, n trailing zeros can be found as each 5 can generate a 0.s
    int l = 1, r = 5 * n;
    while (l < r) {
        int m = l + (r - l) / 2;
        int zeros = count(m);
        if (zeros < n)
            l = m + 1;
        else
            r = m;
    }
    return l;
}