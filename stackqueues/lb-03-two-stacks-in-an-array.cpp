// Given a single array implement two stacks in it.
class towStacks {
    int *arr;
    int size;
    int top1, top2;
    twoStacks(int n = 10) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int);
    void push2(int);
    int pop1();
    int pop2();
} void twoStacks ::push1(int x) {
    if (top1 < top2)
        arr[++top1] = x;
}

// Function to push an integer into the stack2.
void twoStacks ::push2(int x) {
    if (top1 < top2)
        arr[--top2] = x;
}

// Function to remove an element from top of the stack1.
int twoStacks ::pop1() {
    if (top1 >= 0)
        return arr[top1--];
    return -1;
}

// Function to remove an element from top of the stack2.
int twoStacks ::pop2() {
    if (top2 < size)
        return arr[top2++];
    return -1;
}