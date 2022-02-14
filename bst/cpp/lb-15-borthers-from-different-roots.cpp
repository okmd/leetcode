// create a map of required sum from one bst O(n)space
// find the required sum from the other bst O(n) time.
// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
void create_map(Node *root, int sm, unordered_map<int, bool> &mapping){
    if(!root) return;
    create_map(root->left, sm, mapping);
    mapping[sm - root->data]=true;
    create_map(root->right, sm, mapping);
}
void find_required_sum(Node*root, int sm, vector<pair<int, int>> &ans, unordered_map<int, bool> &mapping){
    if(!root) return;
    if(mapping.find(root->data)!=mapping.end()){
        ans.push_back(make_pair(root->data, sm-root->data));
    }
    find_required_sum(root->left, sm, ans, mapping);
    find_required_sum(root->right, sm, ans, mapping);


}
vector<pair<int, int>> pairs_with_sum(Node* root1, Node*root2, int x){
    unordered_map<int, bool> mapping;
    // create map from one tree
    create_map(root1, x, mapping);
    // take values from other tree to make the sum
    vector<pair<int, int>> ans;
    find_required_sum(root2, x, ans,mapping);
    return ans;
}