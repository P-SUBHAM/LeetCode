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
// Approach 1 : Recursion 
// return (root->val >= valx) + goodNodesR(root->left,max(valx,root->val)) +  goodNodesR(root->right,max(valx,root->val));
class Solution {
public:
    int goodNodesR(TreeNode* root, int valx) {
        if(root == NULL) return 0;
        return (root->val >= valx) + goodNodesR(root->left,max(valx,root->val)) +  goodNodesR(root->right,max(valx,root->val));
    }
    int goodNodes(TreeNode* root) {
        return goodNodesR(root,INT_MIN); // choose smallest default value
    }
};