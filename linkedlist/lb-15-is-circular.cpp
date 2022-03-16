bool isCircular(Node *head) {
    Node *temp = head;
    while (temp and temp->next != head) {
        temp = temp->next;
    }
    return (temp) ? 1 : 0;
}