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
    // return global diameter, maxpath length through node
    pair<int,int> diaMaxPathf(TreeNode* root) {
        if(root == NULL) {
            return {0,0};
        }
        pair<int,int> left = diaMaxPathf(root->left);
        pair<int,int> right = diaMaxPathf(root->right);
        // global                       local current node
        // (left dia, right dia) <-> (left path + right path)
        return {max(max(left.first,right.first),left.second+right.second),
                1 + max(left.second,right.second)};
                // path length 1 + max(left path , right path)
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diaMaxPathf(root).first;
    }
};