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
        pre_order(root->left, res);  
    pre_order(root->right, res); 
    res.push_back(root->val);
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    // return pre_order(root, res);
    
//     stack<TreeNode*> st1;
//     stack<TreeNode*> st2;
    
    if (!root) return res;
//     st1.push(root);
//     while (!st1.empty()){
//         TreeNode* node = st1.top();
//         st1.pop();
//         if (node->left) st1.push(node->left);
//         if (node->right) st1.push(node->right);
//         st2.push(node);
//     }
    
//     while (!st2.empty()){
//         TreeNode* temp = st2.top();
//         res.push_back(temp->val);
//         st2.pop();
//     }
//     return res;
    
    TreeNode* curr = root;
    TreeNode* temp;
    
    stack<TreeNode*> st;
    
    while (curr != nullptr || !st.empty()){
        if (curr != nullptr){
            st.push(curr);
            curr = curr->left;
        }
        else {
            temp = st.top()->right;
            if (!temp){
                temp = st.top();
                st.pop();
                res.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->val);
                }
            }
            else {
                curr = temp;
            }
        }
    }
    return res;
}
};