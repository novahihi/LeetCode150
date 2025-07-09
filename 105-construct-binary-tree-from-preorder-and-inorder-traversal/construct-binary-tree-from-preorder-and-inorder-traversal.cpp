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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    stack <TreeNode*> st;
    st.push(root);
    int iodid = 0;
    for (int i = 1; i<preorder.size(); i++) {
        TreeNode* temp = st.top();
        int cur = preorder[i];
        if (temp->val!=inorder[iodid]) {
            temp->left = new TreeNode (cur);
            st.push(temp->left);
        }
        else {
        while (!st.empty() && st.top()->val==inorder[iodid]) {
            temp = st.top();
            st.pop();
            iodid++;
        }
        temp->right = new TreeNode (cur);
        st.push(temp->right);
    }
    }
    return root;
    }
};