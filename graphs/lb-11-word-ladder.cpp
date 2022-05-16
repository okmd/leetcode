int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, int> mp;
    for (int i = 0; i < wordList.size(); i++) {
        mp[wordList[i]] = 1;
    }

    if (mp.find(endWord) == mp.end()) return 0;

    queue<string> q;
    q.push(beginWord);
    int depth = 0;
    while (q.size()) {
        depth++;
        int qs = q.size();
        for (int i = 0; i < qs; i++) {
            string curr = q.front();
            q.pop();
            // apply 26 transformation
            for (int j = 0; j < curr.size(); j++) {
                string next_word = curr;
                for (char c = 'a'; c <= 'z'; c++) {
                    next_word[j] = c;
                    if (next_word == curr) continue;
                    if (next_word == endWord) return depth + 1;
                    if (mp.find(next_word) != mp.end()) {
                        q.push(next_word);
                        mp.erase(next_word);
                    }
                }
            }
        }
    }
    return 0;
}