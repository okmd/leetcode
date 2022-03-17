// Delete a node in circular ll
Node *deleteNode(Node *head, int key) {
    if (!head) return head;
    // only one element and match with key
    if (head->data == head->next->data and head->data == key) return NULL;
    // assuming all keys are unique
    Node *temp = head;
    Node *prev = NULL;
    while (temp->data != key and temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    // first element to remove
    if (head->data == key) {
        Node *t = head;
        // find tail and point to new head
        while (t->next != head) {
            t = t->next;
        }
        t->next = head->next;
        return head->next;
    }
    // if key not found
    if (temp->next == head and temp->data != key) return head;
    // if temp exits i.e key found
    prev->next = temp->next;
    return head;
}