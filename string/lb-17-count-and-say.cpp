// given n find the nth sequence in the count and say sequence;
// from ith to i+1th sequence
// 22233444=>322334::count,say
// idea is to find count of each unique digit and make new strgin by appdending cout of current_number and current_number;

string countAndSay(int n) {
    // base case
    if (n == 1) return "1";
    // for n>=2
    string prev = "1#";
    // for nth sequence
    while (--n) {
        // intermediate sequence;
        string ans;
        int i = 1;
        // foreach unique char create sequence
        while (i < prev.size()) {
            int count = 1;
            // current number count
            while (prev[i] == prev[i - 1]) {
                i++;
                count++;
            }
            // append count+number;
            ans = ans + to_string(count) + prev[i - 1];
            // move to next unique no
            i++;
        }
        // append end delimeter as this is new sequence for next iteration.
        prev = ans + "#";
    }
    // remove # and return as ans
    return prev.substr(0, prev.size() - 1);
}