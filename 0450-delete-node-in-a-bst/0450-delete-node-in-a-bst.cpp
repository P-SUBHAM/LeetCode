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

// Approach 1: BST node deletion by replacing with min in right subtree 
class Solution {
public:
    int findmin(TreeNode *root) {
        if(root->left == NULL) return root->val;
        return findmin(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key > root->val) {
            root->right = deleteNode(root->right,key);
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left,key);
        }
        else {
            if(root->left == NULL)
                return root->right;
            if(root->right == NULL)
                return root->left;
            int x = findmin(root->right);
            root->val = x;
            root->right = deleteNode(root->right,x);
        }
        return root;
    }
};