vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    while (a.size()) {
        b.push_back(a.front());
        push_heap(b.begin(), b.end());
        pop_heap(a.begin(), a.end());
        a.pop_back();
    }
    return b;
}