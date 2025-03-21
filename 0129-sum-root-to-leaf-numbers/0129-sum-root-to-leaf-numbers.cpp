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
// Approach 1: Tree Recursion
class Solution {
public:
    int f(TreeNode*root,int sum) {
        if(root->left==NULL&&root->right==NULL) return 10*sum+root->val;
        int sumn = sum*10+root->val;
        int l = 0, r = 0;
        if(root->left==NULL && root->right!=NULL) {
            r = f(root->right,sumn);
        }
        else if(root->left!=NULL&&root->right==NULL) {
            l = f(root->left,sumn);
        }
        else {
            l = f(root->left,sumn);
            r = f(root->right,sumn);
        }
        int ans = l+r;
        cout<<ans<<endl;
        return ans;
    }
    int sumNumbers(TreeNode* root) {
        return f(root,0);
    }
};