class Solution {
   public:
    int carry = 0;
    int sm = 0;
    Node* helper(Node* head) {
        // last element add 1 and propagate carry
        if (!head->next) {
            sm = head->data + 1;
            carry = sm / 10;
            head->data = sm % 10;
            return head;
        }
        Node* temp = helper(head->next);
        // propagate carry
        if (carry > 0) {
            sm = head->data + carry;
            carry = sm / 10;
            head->data = sm % 10;
        }
        head->next = temp;
        return head;
    }
    Node* addOne(Node* head) {
        head = helper(head);
        // for 999+1
        // if still carry exits
        if (carry > 0) {
            Node* temp = new Node(carry);
            temp->next = head;
            return temp;
        }
        return head;
    }
};