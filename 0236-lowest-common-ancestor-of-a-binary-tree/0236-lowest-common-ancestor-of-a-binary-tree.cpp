/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Approach 2: Using recursion simple
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) 
            return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        return root; // means one element found on left and right
    }
};


class Solution1 {
public:
    bool f(TreeNode* root, TreeNode* x) {
        if(root==0) return false;
        if(root->val==x->val) {
            return true;
        }
        return f(root->left,x) || f(root->right,x);
    }
    TreeNode*  lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val) return root;
        bool pl = false;
        if(f(root->left,p)) {
            pl = true;
        }
        bool ql = false;
        if(f(root->left,q)) {
            ql = true;
        }
        if(pl==ql && pl == true) {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(pl==ql&&pl==false) {
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};