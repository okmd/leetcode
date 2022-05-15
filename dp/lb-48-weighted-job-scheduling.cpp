// LC: 1235
// 1. sot by finish time
// 2. get max profit from either including  or excluding current element or not
// 3. dont take conflicting jobs.
// TLE

class Jobs {
   public:
    int start, end, profit;
    Jobs(int st, int ed, int pr) {
        start = st;
        end = ed;
        profit = pr;
    }
};
// TLE ON LC
int nonConflictingJob(vector<Jobs*> arr, int i) {
    // is there any conflicting job before ith job
    for (int j = i - 1; j >= 0; j--) {
        if (arr[j]->end <= arr[i - 1]->start) return j;
    }
    return -1;
}
int helper(vector<Jobs*> arr, int n) {
    if (n == 1) return arr[n - 1]->profit;
    int exclude = helper(arr, n - 1);
    int include = arr[n - 1]->profit;
    int i = nonConflictingJob(arr, n);
    if (i != -1) include += helper(arr, i + 1);
    return max(include, exclude);
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<Jobs*> arr;
    int n = profit.size();
    for (int i = 0; i < n; i++) {
        arr.push_back(new Jobs(startTime[i], endTime[i], profit[i]));
    }
    sort(arr.begin(), arr.end(), [](auto a, auto b) {
        return a->end < b->end;
    });
    return helper(arr, n);
}
//
// TLE ON LC
bool overlapping(Jobs* a, Jobs* b) {
    return a->end > b->start;
}
int helper(vector<Jobs*> arr, int n) {
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i]->profit;
    }
    int mx = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (!overlapping(arr[j], arr[i])) {
                dp[i] = max(arr[i]->profit + dp[j], dp[i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        mx = max(mx, dp[i]);
    return mx;
}