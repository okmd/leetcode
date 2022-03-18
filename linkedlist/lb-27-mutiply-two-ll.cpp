
// 1->2->3
// 2->4
// ans = -2
long long multiplyTwoLists(Node* l1, Node* l2) {
    long long mod = 1000000000 + 7, n1 = 0, n2 = 0;
    Node *temp1 = l1, *temp2 = l2;
    while (temp1) {
        n1 = ((n1 % mod) * 10) % mod + temp1->data;
        temp1 = temp1->next;
    }
    while (temp2) {
        n2 = ((n2 % mod) * 10) % mod + temp2->data;
        temp2 = temp2->next;
    }
    return ((n1 % mod) * (n2 % mod)) % mod;
}