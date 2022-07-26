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
    int ans;
    int maxPathSumUtil(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int l = maxPathSumUtil(root->left);
        int r = maxPathSumUtil(root->right);
        int nodemaxv = max({root->val,root->val+l,
                            root->val+r,root->val+l+r});
        ans = max(ans,nodemaxv);
        int SinglePathSum = max({root->val,root->val+l,
                                root->val+r});
        return SinglePathSum;
        
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxPathSumUtil(root);
        return ans;
    }
};