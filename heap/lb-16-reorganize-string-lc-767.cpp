// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.
string reorganizeString(string s) {
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }
    // create max-heap, freq, char
    priority_queue<pair<int, char>> heap;
    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            heap.push({freq[i], 'a' + i});
        }
    }
    // max frequent element is at top
    pair<int, char> top = heap.top();
    heap.pop();
    string ans;
    // elemenent with highest frequency
    // and it can be repeated to make non-adjacent but less frequent element will fail to do the same.
    ans.push_back(top.second);
    top.first--;
    while (heap.size()) {
        // adjacent element which is not same but can have same frequency
        pair<int, char> temp = heap.top();
        heap.pop();
        // reduce its frequency
        temp.first--;
        // take it in ans
        ans.push_back(temp.second);
        // if still can be used
        if (top.first > 0) {
            // push to heap
            heap.push(top);
        }
        // now take this to make alternate
        top = temp;
    }
    if (top.first > 0) return "";
    return ans;
}