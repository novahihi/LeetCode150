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
    int countNodes(TreeNode* root) {
    if (!root) return 0;
    int cnt = 1;
    stack <TreeNode*> st;
    st.push (root);
    while (!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();
        if (temp->right) {
            st.push(temp->right);
            cnt++;
        }
        if (temp->left) {
            st.push(temp->left);
            cnt++;
        }
    }  
    return cnt;
    }
};