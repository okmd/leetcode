int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) arr.push_back(make_pair(start[i], end[i]));
    // sort based on the end time so that small meetings can be scheduled first
    // it will generate maximum meerings
    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    // can be scheduled only if current start > previous end
    pair<int, int> prev = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        // prev meeting finished, now schedule current
        if (arr[i].first > prev.second) {
            // increase count of meeting in room
            count++;
            // make current meeting as prev
            prev = arr[i];
        }
    }
    return count;
}