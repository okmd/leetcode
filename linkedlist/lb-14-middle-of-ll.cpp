ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}