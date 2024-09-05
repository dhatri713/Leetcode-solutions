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
    vector<int>& in_order(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return res;
    in_order(root->left, res);  
    res.push_back(root->val);
    in_order(root->right, res); 
    return res;
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
    return in_order(root, res);
    }
};