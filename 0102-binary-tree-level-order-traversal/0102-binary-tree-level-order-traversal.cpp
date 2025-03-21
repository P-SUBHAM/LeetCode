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
// Approach 1 : Level Order Traversal using bfs and qu
// get size of qu, pop that many nodes, push not NULL child into qu
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> level;
        if(!root) return level;
        while(!qu.empty()) {
            int sz = qu.size();
            vector<int> v;
            for(int i = 0; i < sz; i++) {
                TreeNode* curr = qu.front(); qu.pop();
                v.push_back(curr->val);
                if(curr->left) {
                    qu.push(curr->left);
                }
                if(curr->right) {
                    qu.push(curr->right);
                }
            }
            level.push_back(v);
        }
        return level;
    }
};