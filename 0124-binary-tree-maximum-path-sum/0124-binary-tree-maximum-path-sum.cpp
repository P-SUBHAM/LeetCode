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
// practice

class Solution {
public:
    int ans;
    int maxPathS(TreeNode* root) {
        if(root == NULL) return -1e9;
        int l = maxPathS(root->left), r = maxPathS(root->right), x = root->val;
        ans = max({ans,l+x+r,l+x,x+r,l,r,x});
        return max({x,x+max(l,r)});
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        ans = root->val;
        maxPathS(root);
        return ans;
    }
};

class Solution1 {
public:
    int ans;
    int maxPathSumRoot(TreeNode* root) {
        if(!root) return -1e6;
        int l = maxPathSumRoot(root->left);
        int r = maxPathSumRoot(root->right);
        int x = root->val;
        int currmax = max(x,x+max(l,r));
        ans = max({ans,l,r,l+x,r+x,l+r+x,x}); // l,r handled in recur
        return currmax;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxPathSumRoot(root);
        return ans;
    }
};