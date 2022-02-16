// Give a root node of binary tree
// find the largest sub bst within the given binary tree
// leaf nodes are bst of size 1
// Brute force O(n^2)
// find each element check isBst if yes then maintain a max count by counting the number of nodes in it
// 1. visit each node and find is bst at this node
// 1.1 if yes then count nodes in it and update max count
// 1.2 else leave as it is


// method 2: O(n)
// Visit nodes from bottom to top i.e leaves to root
// leaves are always bst
// maintain 3 things at each variable bst size, maximum of left sub bst and minium of right bst.
// as max of left bst will < root < min of right bst
// if not bst then reset min and max to int_min and int_max
class Triplet {
   public:
    int size;
    int minimum;
    int maximum;
    Triplet(int sz = 0, int mn = INT_MIN, int mx = INT_MAX) {
        size = sz;     // size of the largest bst till current node
        minimum = mn;  // minimum node value in right subtree as root<min(right)
        maximum = mx;  // maximum node value if left subtree as root>max(left)
    }
};
Triplet* largest_bst(Node* root) {
    // assign large number in mimimum such that is can be compared right->minimum>root->data
    // similarly assign smallest number such that it can be compated left->max<root->data
    // useful when the left or child is not present
    if (!root) return new Triplet(0, INT_MAX, INT_MIN);  // same as when we need to find max then we take min if anything comes greator then we take it as max.
    // leaf is always bst
    if (!root->left and !root->right) return new Triplet(1, root->data, root->data);
    // post order traversals
    Triplet* left = largest_bst(root->left);
    Triplet* right = largest_bst(root->right);
    if (left->maximum < root->data and right->minimum > root->data)
        // size will be left subtree + right subtree and itself
        // new minimum will be minimum right side and current node value as right may not exits(+inf)
        // similarly for maximum of left side
        return new Triplet(1 + left->size + right->size, min(root->data, left->minimum), max(root->data, right->maximum));
    return new Triplet(max(left->size, right->size));
}