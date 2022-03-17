Node *reverseDLL(Node *head) {
    // reverse dll
    if (!head) return head;
    // only one node
    // if(!head->prev and !head->next) return head;

    Node *curr = head;
    Node *prev = NULL, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        // ------------//
        // prev = curr->prev;
        // curr->prev = curr->next;
        // curr->next = prev;
        // next = curr; // current head return it at end
        // curr = curr->prev;
    }
    return prev;
}