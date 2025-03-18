/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Approach 1: recursive approach BST LCA p root q 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l = p->val, m = root->val, r = q->val;
        if(l > r) swap(l,r);
        if(l <= m && m <= r) return root;
        if(m <= l && m <= r) return lowestCommonAncestor(root->right,p,q);
        return lowestCommonAncestor(root->left,p,q);
    }
};