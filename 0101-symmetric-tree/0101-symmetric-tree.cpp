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
// Approach 1: check if child nodes are symmetric or not recursion logic
class Solution {
public:
    bool def(TreeNode* rootl, TreeNode* rootr) {
        if(rootl == 0) return rootr == 0;
        if(rootr == 0) return rootl == 0;
        if(rootl->val != rootr->val) return false;
        return def(rootl->right,rootr->left) && def(rootl->left,rootr->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return def(root->left,root->right);
    }
};