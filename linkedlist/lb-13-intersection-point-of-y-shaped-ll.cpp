int intersectPoint(Node *head1, Node *head2) {
    // find the length of each ll
    // now move n1-n2 steps in longer ll only
    // now move in both then you will end-up at intersection point
    int n1 = 0, n2 = 0;
    Node *temp = head1;
    // find distance of list 1
    while (temp) {
        n1++;
        temp = temp->next;
    }
    // find distance of list 2
    temp = head2;
    while (temp) {
        n2++;
        temp = temp->next;
    }
    // extra part to ommit
    int diff = abs(n1 - n2);
    Node *temp1 = head1;
    Node *temp2 = head2;
    if (n1 > n2) {
        while (diff--) temp1 = temp1->next;
    } else {
        while (diff--) temp2 = temp2->next;
    }
    // now move both
    while (temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1->data;
}