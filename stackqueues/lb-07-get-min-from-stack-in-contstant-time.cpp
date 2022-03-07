int min_ele = INT_MAX;

void push(stack<int>& s, int a) {
    if (isEmpty(s)) {
        s.push(a);
        min_ele = a;
        return;
    }
    if (a < min_ele) {
        s.push(2 * a - min_ele);
        min_ele = a;
    } else
        s.push(a);
}

bool isFull(stack<int>& s, int n) {
    return s.size() == n;
}

bool isEmpty(stack<int>& s) {
    return s.size() == 0;
}

int pop(stack<int>& s) {
    if (isEmpty(s)) return -1;
    // Your code goes here
    int pp = s.top();
    if (pp < min_ele) {
        min_ele = 2 * min_ele - pp;
    }
    s.pop();
    return pp;
}

int getMin(stack<int>& s) {
    return min_ele;
}