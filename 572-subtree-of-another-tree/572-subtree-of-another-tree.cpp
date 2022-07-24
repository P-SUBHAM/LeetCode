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
    bool isIdenticalTree(TreeNode* r1, TreeNode* r2) {
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        if(r1 == NULL) {
            return false;
        }
        if(r2 == NULL) {
            return false;
        }
        if(r1->val != r2->val) {
            return false;
        }
        return isIdenticalTree(r1->left,r2->left) && isIdenticalTree(r1->right,r2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(subRoot == NULL) {
            return true;
        }
        if(root == NULL) {
            return false;
        }
        if(root->val == subRoot->val) {
            return isIdenticalTree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};