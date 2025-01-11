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
// Approach 1: Modified Level Ordered Traversal T:O(n) S:O(n)
// changing dir at next level and pushing accordingly into array
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        if(root == NULL) {return ans;}
        qu.push(root);
        qu.push(NULL);
        vector<int> level;
        bool dir = 1;
        while(!qu.empty()) {
            TreeNode *node = qu.front();
            qu.pop();
            if(node == NULL) {
                if(!dir) reverse(level.begin(),level.end());
                dir ^= 1;
                ans.push_back(level);
                level.clear();
                if(!qu.empty()) {
                    qu.push(NULL);
                }
            }
            else {
                level.push_back(node->val);
                if(node->left!=NULL) {qu.push(node->left);}
                if(node->right!=NULL) {qu.push(node->right);}
            }
        }
        return ans;
    }
};