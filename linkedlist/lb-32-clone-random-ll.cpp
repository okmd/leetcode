// BruteForce: Store <Node,Node> for each node
// traverse for each node and find link and create same link in copy stored in map.
// Time ans space: O(n)

// Cant point to random pointer as it may be present at that time.
// Optimization:
// 1. Create copy node in between i.e after next node.
// 2. start from head and point random;s to new copy node.
Node *copyList(Node *head) {
    if (!head) return head;
    Node *curr = head, *temp;
    // 1. create copy node
    while (curr) {
        // create a node in middle and change next pointers only.
        temp = new Node(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = curr->next->next;
    }
    // 2. assign random links
    curr = head;
    while (curr) {
        // find random pointer and assign if exits
        curr->next->arb = (curr->arb) ? curr->arb->next : curr->arb;
        // move to next node of original list
        curr = curr->next->next;
    }
    // correct original list link
    curr = head;
    head = curr->next;  // new head
    while (curr) {
        // copied node
        temp = curr->next;
        // re-assigend to original list
        curr->next = curr->next->next;
        // move to next node of original list
        curr = temp->next;
        // connect the new node to next new node
        temp->next = (curr) ? curr->next : curr;
    }
    return head;
}