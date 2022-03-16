// Given a sorted linked list
// remove duplicate elements without extra space
// as the list is sorted, so duplicate will occur next to each other if exists.
Node *removeDuplicates(Node *head) {
    Node *temp1 = head;
    while (temp1) {
        Node *temp = temp1;
        while (temp and temp->next and temp->data == temp->next->data) {
            temp = temp->next;
        }
        // remove
        temp1->next = temp->next;
        temp1 = temp1->next;
    }
    return head;
}