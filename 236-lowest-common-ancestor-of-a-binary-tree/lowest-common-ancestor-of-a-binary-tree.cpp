/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* temp;
    unordered_set <TreeNode*> pi;
    map <TreeNode*, TreeNode*> m;
    m[root] = nullptr;
    stack <TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        temp = st.top();
        st.pop();
            if (temp->left) {
                st.push(temp->left);
                m[temp->left] = temp;
            }
            if (temp->right) {
                st.push(temp->right);
                m[temp->right] = temp;
            }
        }
    while (p!=nullptr) {
        pi.insert(p);
        p = m[p];
    }
    while (q!=nullptr) {
        if (pi.count(q)) return q;
        q = m[q];
    }

    return root;
    }
};