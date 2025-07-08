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
    int kthSmallest(TreeNode* root, int k) {
    stack <TreeNode*> st;
    TreeNode* cur = root;
    while (!st.empty() || cur!=nullptr) {
        while (cur!=nullptr) {
            st.push (cur);
            cur = cur->left;
        }
    //xu ly node
    cur = st.top();
    st.pop();
    k--;
    if (k==0) return cur->val;
    cur = cur->right;
    }
    return root->val;
    }
};