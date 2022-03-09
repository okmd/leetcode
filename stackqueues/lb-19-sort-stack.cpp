void SortedStack ::sort() {
    stack<int> monotonically_decreasing;
    // create monotonically decreasing stack
    while (s.size()) {
        int current_element = s.top();
        s.pop();
        if (monotonically_decreasing.size() == 0)
            monotonically_decreasing.push(current_element);
        else if (monotonically_decreasing.top() > current_element)
            monotonically_decreasing.push(current_element);
        else {
            stack<int> temp;
            while (monotonically_decreasing.size() and monotonically_decreasing.top() < current_element) {
                temp.push(monotonically_decreasing.top());
                monotonically_decreasing.pop();
            }
            monotonically_decreasing.push(current_element);
            while (temp.size()) {
                monotonically_decreasing.push(temp.top());
                temp.pop();
            }
        }
    }
    // change the content of stack
    while (monotonically_decreasing.size()) {
        s.push(monotonically_decreasing.top());
        monotonically_decreasing.pop();
    }
}