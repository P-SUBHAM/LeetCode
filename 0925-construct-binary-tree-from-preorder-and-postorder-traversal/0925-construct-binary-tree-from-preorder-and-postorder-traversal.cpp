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
    TreeNode* constructTreeRec(vector<int>& preorder, int &prei, vector<int>& postorder, int &posti, int n) {
        if(prei >= n || posti >= n) return NULL;
        TreeNode* root = new TreeNode(preorder[prei++]);
        // if(root->val==postorder[posti]) {
        //     posti++; return root;
        // }
        if(root->val!=postorder[posti])
            root->left = constructTreeRec(preorder, prei, postorder, posti, n);
        if(root->val!=postorder[posti])
            root->right = constructTreeRec(preorder, prei, postorder, posti, n);
        posti++;
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int prei = 0, posti = 0;
        return constructTreeRec(preorder,prei,postorder,posti,preorder.size());
    }
};