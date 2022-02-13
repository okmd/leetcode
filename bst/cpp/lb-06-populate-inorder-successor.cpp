class Solution {
   public:
    Node *succ = NULL;

    void populateNext(Node *root) {
        if (!root) return;
        // move right as the successor would come from either root or right for left subtree.
        populateNext(root->right);
        // change the the next pointer to point the successor.
        root->next = succ;
        succ = root;
        // call to the left
        populateNext(root->left);
    }
};