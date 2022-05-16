void dfs(string curr, string endWord, unordered_map<string, vector<string>> &adj, vector<string> &row, vector<vector<string>> &ans) {
    row.push_back(curr);
    if (curr == endWord) {
        ans.push_back(row);
        row.pop_back();
        return;
    }
    for (auto word : adj[curr]) {
        dfs(word, endWord, adj, row, ans);
    }
    row.pop_back();
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> visited;
    for (int i = 0; i < wordList.size(); i++) {
        mp[wordList[i]] = 1;
    }

    if (mp.find(endWord) == mp.end()) return ans;

    queue<string> q;
    q.push(beginWord);
    visited[beginWord] = 0;
    while (q.size()) {
        string curr = q.front();
        q.pop();
        string next_word = curr;
        // apply 26 transformation
        for (int j = 0; j < curr.size(); j++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (next_word[j] == c) continue;
                next_word[j] = c;
                if (mp.find(next_word) != mp.end()) {
                    // if new formed word is present in dict and not visited
                    // coming first time hence its depth is 1 more than parent.
                    if (visited.find(next_word) == visited.end()) {
                        visited[next_word] = visited[curr] + 1;
                        q.push(next_word);
                        adj[curr].push_back(next_word);
                        // if formed word is already present, i.e someone has already reached to this word
                        // consider only next level word not same level or previous level
                    } else if (visited[next_word] == 1 + visited[curr]) {
                        adj[curr].push_back(next_word);
                    }
                }
            }
            next_word[j] = curr[j];  // next_word = curr
        }
    }
    // apply dfs to generate all paths
    vector<string> temp;
    dfs(beginWord, endWord, adj, temp, ans);
    // for(auto x:adj){
    //     cout<<x.first<<"-> ";
    //     for(auto word:x.second){
    //         cout<<word<<" ";
    //     }
    //     cout<<endl;
    // }

    return ans;
}
// Create adjancency list to represent only next level node not same level or previous level
// as going to same level or previous will cause the more distance.
// now apply dfs to the adj list to generate all paths.