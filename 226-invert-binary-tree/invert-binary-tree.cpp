class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->right);
    invertTree(root->left);
    return root;
    }
};