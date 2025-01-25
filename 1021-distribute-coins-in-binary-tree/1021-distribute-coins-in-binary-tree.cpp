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
// Approach 1: recursion
// calculate extra coin at each node add abs to ans and ret to parent
class Solution {
public:
    int ans = 0;
    int f(TreeNode* root) {
        if(root == NULL) return 0;
        int l = f(root->left); // call f not distributeCoins
        int r = f(root->right);
        int ex = l+r+(root->val)-1;
        ans += abs(ex);
        return ex;
    }
    int distributeCoins(TreeNode* root) {
        ans = 0;
        f(root);
        return ans;
    }
};