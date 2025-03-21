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
// Approach 1: Recursion
// start with range possible for any node, if the value in preorder list is in range include it else skip it
class Solution {
public:
    int i,n;
    TreeNode* createBST(vector<int>& preorder, int low, int high) {
        if(i==n) return NULL;
        int x = preorder[i];
        if(x < low || x > high) return NULL;
        TreeNode* node = new TreeNode(x); i++; // low<x<high
        node->left = createBST(preorder,low,x);
        node->right = createBST(preorder,x,high);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        i = 0, n = preorder.size();
        return createBST(preorder,-1e8,1e8);
    }
};