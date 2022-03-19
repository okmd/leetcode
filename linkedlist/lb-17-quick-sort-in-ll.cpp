class Triplet {
   public:
    Node *left, *right, *pivot;
    Triplet() {
        left = NULL;
        right = NULL;
        pivot = NULL;
    }
};
Triplet seggrigate(Node *head) {
    // find pivot and split list into three parts
    // left all nodes less than pivot
    // right all nodes more than pivot
    // take 1st node as pivot
    Node *pivot = head;
    Node *left = new Node(-1);
    Node *right = new Node(-1);
    Node *leftH = left, *rightH = right;
    Node *curr = head->next;
    while (curr) {
        if (curr->data < pivot->data) {
            left->next = curr;
            left = left->next;
        } else {
            right->next = curr;
            right = right->next;
        }
        curr = curr->next;
    }
    // mark end
    left->next = NULL;
    right->next = NULL;
    pivot->next = NULL;
    // triplet
    Triplet t;
    t.left = leftH->next;
    t.right = rightH->next;
    t.pivot = pivot;
    // delete pointer
    return t;
}
Node *merge(Node *left, Node *mid, Node *right) {
    // either left or right can be null
    if (!left) {
        // as pivot is only one element
        mid->next = right;
        return mid;
    }
    if (!right) {
        Node *temp = left;
        // move to end of left sorted list and join mid
        while (temp->next)
            temp = temp->next;
        temp->next = mid;
        return left;
    }
    // both exits
    // move to left end
    Node *l1 = left;
    while (l1->next) l1 = l1->next;
    l1->next = mid;
    mid->next = right;
    return left;
}
Node *quickSort1(Node *head) {
    if (!head) return head;
    // seggrigate list into three parts left, pivo, right
    Triplet t = seggrigate(head);
    Node *left = t.left, *right = t.right, *mid = t.pivot;
    left = quickSort1(left);
    right = quickSort1(right);
    // merge all sorted parts
    head = merge(left, mid, right);
    return head;
}
