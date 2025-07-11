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
    void flatten(TreeNode* root) {
    if (!root) return;
    queue <TreeNode*> q;
    stack <TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();
        q.push(temp);
        if (temp->right) st.push (temp->right);
        if (temp->left) st.push (temp->left);
    } 
    while (q.size()!=1) {
        TreeNode* temp = q.front();
        q.pop();
        temp->right = q.front();
        temp->left = nullptr;
    } 
    q.front()->right = nullptr;
    }
};