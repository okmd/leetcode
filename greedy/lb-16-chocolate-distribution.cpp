// Give n packet of chocolates
// distrubute the chocholoate to m students such that the difference between the
// minimum and maximum chocolate is minimum

long long findMinDiff(vector<long long> a, long long n, long long m) {
    // n = number of chocolate packets
    // m = number of students
    // a arr of chocolates
    // sort the array so that m countinious chocolates can me give to m students
    // difference will be mimimum only when min and max are closer,
    // it is only possible if the elements are sorted.
    sort(a.begin(), a.end());
    int i = 0, j = m - 1;
    long long diff = INT_MAX;
    while (j < n) {
        // array between i and j represents the chocolates of m students
        diff = min(a[j] - a[i], diff);
        j++;
        i++;
    }
    return (diff != INT_MAX) ? diff : 0;
}
