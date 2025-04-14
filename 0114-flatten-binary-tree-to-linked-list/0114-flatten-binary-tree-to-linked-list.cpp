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
    TreeNode* flattenPreOrder(TreeNode* root) {
        if(root == NULL) return root;
        if(root->left == NULL && root->right == NULL) return root;
        TreeNode *templeft = flattenPreOrder(root->left);
        TreeNode *tempright = flattenPreOrder(root->right);
        if(templeft != NULL) {
            templeft->right = root->right;
            root->right = root->left; root->left = NULL;
        }
        return (tempright==NULL)?templeft:tempright;
    }
    void flatten(TreeNode* root) {
        flattenPreOrder(root);
    }
};