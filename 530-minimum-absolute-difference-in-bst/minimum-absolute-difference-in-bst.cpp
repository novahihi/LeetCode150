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
    int getMinimumDifference(TreeNode* root) {
    if (!root) return 0;
    int mini = 999999;
    stack <TreeNode*> st;
    TreeNode* prev = nullptr;
    TreeNode* curr = root;
        while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        if (prev) mini = min(mini, curr->val - prev->val);
        prev = curr;

        curr = curr->right;
    }
   
    return mini;
    }
};