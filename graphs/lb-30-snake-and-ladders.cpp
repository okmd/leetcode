class Solution {
public:
    pair<int, int> coordinate(int pos, int n) {
        int r = n - (pos - 1) / n - 1;
        int c = (pos - 1) % n;
        if ((n & 1 and r & 1) or !(n & 1 or r & 1)) {
            // if n is odd then change to odd rows;
            // if n is even then change the even rows(reverse)
            c = n - c - 1;
        }
        // if(n%2==r%2){
        //     c = n-c-1;
        // }
        return { r, c };
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int, int>> q;
        int n = board.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({ 1, 0 }); // starting index 1 and steps 0
        visited[n - 1][0] = true;
        while (q.size()) {
            auto [pos, steps] = q.front();
            q.pop();
            if (pos == n * n) return steps;
            for (int i = 1; i <= 6; i++) {
                int next_pos = pos + i;
                if (next_pos > n * n) continue;
                auto [r, c] = coordinate(next_pos, n);
                if (!visited[r][c]) {
                    visited[r][c] = true;
                    (board[r][c] == -1) ? q.push({ next_pos, steps + 1 }) : q.push({ board[r][c], steps + 1 });
                }
            }
        }
        return -1;
    }
};