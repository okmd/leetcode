Node *get_mid(Node *head) {
    Node *slow = head, *fast = head->next;
    while (fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *head1, Node *head2) {
    // merge two null terminated ll
    if (!head1) return head2;
    if (!head2) return head1;
    Node *head = new Node(-1);
    Node *temp = head;
    while (head1 and head2) {
        // pick min element
        if (head1->data <= head2->data) {
            head->next = new Node(head1->data);
            head1 = head1->next;
        } else {
            head->next = new Node(head2->data);
            head2 = head2->next;
        }
        head = head->next;
    }
    while (head1) {
        head->next = new Node(head1->data);
        head1 = head1->next;
        head = head->next;
    }
    while (head2) {
        head->next = new Node(head2->data);
        head2 = head2->next;
        head = head->next;
    }
    return temp->next;
}

Node *mergeSort(Node *head) {
    // empty or only one node.
    if (!head or !head->next) return head;
    // find mid
    Node *mid = get_mid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);

    // now slow points to middle of list
}