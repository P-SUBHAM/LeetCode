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
    pair<TreeNode*,TreeNode*> help(TreeNode* root) {
        if(root==0) return {0,0};
        if(root->left==0&&root->right==0) return {root,root};
        if(root->left==0) {
            pair<TreeNode*,TreeNode*> temp = help(root->right);
            temp.first->left=0;
            temp.second->left=0;
            root->left = 0;
            root->right = temp.first;
            return {root,temp.second};
        }
        if(root->right == 0) {
            pair<TreeNode*,TreeNode*> temp = help(root->left);
            temp.second->right = root;
            temp.first->left=0;
            root->left = 0;
            return {temp.first,root};
        }
        pair<TreeNode*,TreeNode*> templ = help(root->left);
        pair<TreeNode*,TreeNode*> tempr = help(root->right);
        templ.second->right= root;
        templ.first->left = 0;
        templ.second->left=0;
        root->right = tempr.first;
        tempr.first->left=0;
        tempr.second->left=0;
        root->left = 0;
        return {templ.first,tempr.second};
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        return help(root).first;
    }
};