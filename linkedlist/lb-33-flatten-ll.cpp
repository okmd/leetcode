// join based on bottom link not next link
Node *join(Node *l1, Node *l2) {
//     if (!l1) {
//         // change next to bottom ptr
//         l2->bottom = l2->next;
//         l2->next = NULL;
//         return l2;
//     };
    if (!l1) return l2;
    if (!l2) return l1;
    Node *temp = new Node(-1);
    Node *head = temp;
    while (l1 and l2) {
        if (l1->data <= l2->data) {
            temp->bottom = l1;
            l1 = l1->bottom;
        } else {
            temp->bottom = l2;
            l2 = l2->bottom;
        }
        temp = temp->bottom;
    }
    while (l1) {
        temp->bottom = l1;
        l1 = l1->bottom;
        temp = temp->bottom;
    }
    while (l2) {
        temp->bottom = l2;
        l2 = l2->bottom;
        temp = temp->bottom;
    }
    return head->bottom;
}
Node *flatten(Node *root) {
    // take down sorted list
    // call recursion for next sub ll
    // now join both sorted ll
    if (!root) return root;
    Node *bottom = root;
    Node *next = flatten(root->next);
    root->next = NULL;
    // join both sorted ll
    Node *head = join(bottom, next);
    return head;
}
