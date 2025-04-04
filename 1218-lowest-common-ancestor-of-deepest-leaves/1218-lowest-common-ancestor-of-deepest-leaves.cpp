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

class Solution2 {
public:
    // Approach 2: Return dist of deepest leaf node, and lowest ancestor for it
    // {node,dist}
    pair<TreeNode*,int> treeRec(TreeNode* root) {
        if(root == NULL) return {NULL,0};
        pair<TreeNode*,int> left = treeRec(root->left);
        pair<TreeNode*,int> right = treeRec(root->right);
        if(left.second > right.second) {
            return {left.first,left.second+1};
        }
        else if(left.second < right.second) {
            return {right.first,right.second+1};
        }
        return {root,left.second+1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<TreeNode*,int> ans = treeRec(root);
        return ans.first;
    }
};

class Solution {
public:
    int maxd = 0;
    TreeNode* leaf = NULL;
    int help(TreeNode* root,int d) {
        if(root==NULL) return d;
        
        int l = help(root->left,d+1);
        int r = help(root->right,d+1);
        cout<<root->val<<" "<<l<<" "<<r<<"\n";
        if(l==r) {
            if(l >= maxd) {
                leaf = root;
                maxd = l;
            }
        }
        return max(l,r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        help(root,0);
        return leaf;
    }
};