Node *divide(int N, Node *head) {
    // create seperate list for even and odd
    Node *evenH = new Node(-1), *oddH = new Node(-1);
    Node *evenT = evenH, *oddT = oddH;
    Node *temp = head;
    while (temp) {
        if (temp->data & 1) {
            // odd
            oddT->next = temp;
            oddT = oddT->next;
        } else {
            evenT->next = temp;
            evenT = evenT->next;
        }
        temp = temp->next;
    }
    // join  even->odd
    evenT->next = oddH->next;
    head = evenH->next;
    oddT->next = NULL;
    delete oddH;
    delete evenH;
    return head;
}