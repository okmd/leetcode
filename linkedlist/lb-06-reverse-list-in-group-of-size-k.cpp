// Method 1:
// push k element in stack and pop to create a k size reverse ll
// O(n) time and O(k)

// Method 2:
// reverse k element and call for next elements to recursively reverse
struct node *reverse(struct node *head, int k) {
    // base case
    if (!head) return NULL;
    struct node *current = head, *next = NULL, *prev = NULL;
    int count = 0;
    // reverse k elements
    while (current && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    // if still elements left the recursively call to reverse
    if (next) head->next = reverse(next, k);
    // as list is reversed->head will point to head of recursion
    // now prev is head
    return prev;
}