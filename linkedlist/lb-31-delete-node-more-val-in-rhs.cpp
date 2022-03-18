// Method 1:
// use stack and push 1st element
// from 2nd element to last element
// if if more then pop  all greator and push current element
// at the end stack contains the ans
// create list @insert at head
// Method 2:
// withoud stack
// reverse ll and start from end
// maintain max element
// if element less than max i.e there exists an element more than this.
Node *reverse(Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *compute(Node *head) {
    // your code goes here
    head = reverse(head);
    Node *curr = head, *prev = NULL;
    int maxx = INT_MIN;
    while (curr) {
        maxx = max(maxx, curr->data);
        if (curr->data < maxx) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }

        curr = curr->next;
    }
    // again reverse
    head = reverse(head);
    return head;
}