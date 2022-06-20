int rearrange(string str) {
    int mp[26] = { 0 };
    for (auto s : str) {
        mp[s - 'a']++;
    }
    priority_queue<int> pq;
    for (int i = 0; i < 26; i++) {
        if (mp[i]) pq.push(mp[i]);
    }
    int prev = pq.top();
    pq.pop();
    while (pq.size()) {
        int curr = pq.top();
        pq.pop();
        prev--;
        if (prev > 0) pq.push(prev);
        prev = curr;
    }
    return prev == 1;
}
// Amazon