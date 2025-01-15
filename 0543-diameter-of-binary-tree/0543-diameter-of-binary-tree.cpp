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
// Approach 1:
// calc maxpath length for left and right and return max
// before return calc global(dia = l_len + r_len)
class Solution1 {
public:
    int ans;
    int maxl(TreeNode *root) { // return longest path from root to leaf
        if(root == NULL) return 0;
        int l = maxl(root->left);
        int r = maxl(root->right);
        int len = 1 + max(l,r);
        ans = max(ans,l+r);
        return len;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        if(root == NULL or (root->left == NULL && root->right == NULL)) return 0;
        ans = max(ans,1+maxl(root->left)+maxl(root->right));
        return ans;
    }
};

/**
 * Approach:
 * 1. Use a recursive function to calculate two values for each node: 
 *    (a) global diameter (longest path in the tree so far) and 
 *    (b) maximum path length from the node to any leaf.
 * 2. The local diameter at a node is the sum of the maximum path lengths 
 *    from its left and right children.
 * 3. Return the maximum of the global diameter and the local diameter, 
 *    with the maximum path length helping propagate the results upward.
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