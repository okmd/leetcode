class Node {
   public:
    int freq;
    char chr;
    Node *left, *right;
    Node(int f, char c) {
        freq = f;
        chr = c;
        left = NULL;
        right = NULL;
    }
};
class Comp {
   public:
    bool operator()(Node *a, Node *b) {
        // max < default
        // minheap >
        return a->freq > b->freq;
    }
};
void pre_order(Node *root, vector<string> &ans, string temp) {
    if (!root) return;
    // if leaf then found the ans as char lies is leaf only
    if (!root->left and !root->right) {
        ans.push_back(temp);
        return;
    }
    temp.push_back('0');
    pre_order(root->left, ans, temp);
    temp.pop_back();
    temp.push_back('1');
    pre_order(root->right, ans, temp);
    temp.pop_back();
}
vector<string> huffmanCodes(string S, vector<int> f, int N) {
    // create min heap of nodes using frequency;
    priority_queue<Node *, vector<Node *>, Comp> pq;
    for (int i = 0; i < N; i++) {
        pq.push(new Node(f[i], S[i]));
    }
    // for each 2 element create a new node and build Huffman tree;
    while (pq.size() > 1) {
        auto left = pq.top();
        pq.pop();
        auto right = pq.top();
        pq.pop();
        auto node = new Node(left->freq + right->freq, '\0');
        node->left = left;
        node->right = right;
        pq.push(node);
    }
    // use preoder to assign codes;
    // heap contains the root of tree
    vector<string> ans;
    pre_order(pq.top(), ans, "");
    return ans;
}