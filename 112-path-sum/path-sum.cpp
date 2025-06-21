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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});

        while (!st.empty()) {
            auto [node, sum] = st.top(); st.pop();
            if (!node->left && !node->right) {
                if (sum == targetSum) return true;
            }
            if (node->right) st.push({node->right, sum + node->right->val});
            if (node->left)  st.push({node->left, sum + node->left->val});
        }
    return false;
    }
};