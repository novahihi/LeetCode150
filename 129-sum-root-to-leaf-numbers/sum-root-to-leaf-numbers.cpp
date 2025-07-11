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
    int sumNumbers(TreeNode* root) {
    unordered_map <TreeNode*, TreeNode*> m;
    m[root] = nullptr;
    vector <TreeNode*> v;
    queue <TreeNode*> q;
    TreeNode* cur;
    q.push(root);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur->left==nullptr && cur->right == nullptr) v.push_back(cur);
        if (cur->left) {
            m[cur->left] = cur;
            q.push(cur->left);
        }
        if (cur->right) {
            m[cur->right] = cur;
            q.push(cur->right);
        }
    }
    int s = 0;
    for (auto e: v) {
        cur = e; long long d = 1;
        while (cur!=nullptr) {
            s = s + (cur->val)*d;
            d = d*10;
            cur = m[cur];
        }
    }
    return s;     
    }
};
