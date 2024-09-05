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
    return pre_order(root, res);
}

};