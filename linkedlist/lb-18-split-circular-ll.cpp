void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    // find mid
    Node *slow = head, *pfast;
    Node *fast = head->next;
    while (fast and fast != head and fast->next != head) {
        slow = slow->next;
        pfast = fast;
        fast = fast->next->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    // make circualr second list
    if (fast == head) {
        // second last node is pfast 
        pfast->next->next = slow->next;
    } else {
        // last node 
        
        fast->next = slow->next;
    }
    // make circular fist list
    slow->next = head;
}