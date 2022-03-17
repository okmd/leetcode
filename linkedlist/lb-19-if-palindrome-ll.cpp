// Check if Linked List is Palindrome
// find middle and reverse 2nd half of list
// now move from head, and middle so both should be same
// O(n) time and O(1) space
Node *reverse(Node *head) {
    if (!head or !head->next) return head;
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(Node *head) {
    if (!head or !head->next) return true;
    // find tail
    Node *slow = head;
    Node *fast = head->next;
    while (fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // now reverse the 2nd half of list
    Node *temp = reverse(slow->next);
    while (head and temp) {
        if (head->data != temp->data) return false;
        head = head->next;
        temp = temp->next;
    }
    return true;
}