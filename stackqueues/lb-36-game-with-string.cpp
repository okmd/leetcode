int minValue(string s, int k) {
    // remove k char from string such that sum(freq) suould be min
    // find all frequency then top k frequencies.
    vector<int> freq(26, 0);
    priority_queue<int> heap;
    // find frequency of each char in string O(n)
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }
    // push all the frequency of presnet elements
    for (int i = 0; i < freq.size(); i++) {
        if (freq[i]) {
            heap.push(freq[i]);
        }
    }

    // create max heap of frequency
    // as any time reduce large frequenecy to reduce squared sum
    while (k--) {
        // element with max frequenecy
        int x = heap.top();
        // remove
        heap.pop();
        // push again by reducing 1 count
        // if k=2, e.g 5, 4, 3 => 4, 4, 3=> 4, 3, 3 => 3, 3, 3 => will have min sequared sum as
        // as compared to 3,4,3 (removing k from top frequency)
        heap.push(--x);
    }
    int sum = 0;
    // find squared sum of all the elements present in heap 
    // as k elements are removed
    while (!heap.empty()) {
        sum += heap.top() * heap.top();
        heap.pop();
    }
    return sum;
}