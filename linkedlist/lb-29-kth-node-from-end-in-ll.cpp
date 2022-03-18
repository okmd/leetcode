// Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int k) {
    // find n-k th node from start
    Node *temp = head;
    int n = 0;
    while (temp) {
        n++;
        temp = temp->next;
    }
    if (k > n) return -1;
    temp = head;
    k = n - k;
    while (k--) {
        temp = temp->next;
    }
    return temp->data;
}