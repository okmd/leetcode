// Given a un sorted linked list
// in O(n) time ans space
// as the list is  not sorted, so duplicate may  not occur next to each other if exists.
Node *removeDuplicates(Node *head) {
    // ordered map
    unordered_map<int, bool> mp;
    Node *temp = new Node(-1);
    Node *tp = temp;
    while (head) {
        if (mp.find(head->data) == mp.end()) {
            mp[head->data] = true;
            temp->next = new Node(head->data);
            temp = temp->next;
        }
        head = head->next;
    }
    // create ll
    return tp->next;
}