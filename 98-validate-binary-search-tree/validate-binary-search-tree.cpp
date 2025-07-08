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
    bool isValidBST(TreeNode* root) {
    long long temp = -9999999999;
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
    if (cur->val<=temp) return false;
    else temp = cur->val;
    cur = cur->right;
    }
    return true;   
    }
};