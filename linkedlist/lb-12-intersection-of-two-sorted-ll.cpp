// Move the smaller one because next greater element may match
Node* findIntersection(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* head = new Node(-1);
    Node* temp = head;
    while (temp1 and temp2) {
        if (temp1->data == temp2->data) {
            temp->next = new Node(temp1->data);
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->data < temp2->data) {
            temp1 = temp1->next;
        } else {
            temp2 = temp2->next;
        }
    }
    // as one of the list ends so there won;t be any intersetion
    return head->next;
}