/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>& pre_order(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return res;
    res.push_back(root->val);
    pre_order(root->left, res);  
    pre_order(root->right, res); 
    return res;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    // return pre_order(root, res);
    stack<TreeNode*> st;
    if (!root) return res;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        res.push_back(node->val);
        st.pop();
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return res;
}

};