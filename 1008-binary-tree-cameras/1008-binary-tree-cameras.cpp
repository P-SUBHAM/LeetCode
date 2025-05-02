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

// Approach 1: Greedy dfs
// bottom up approach 1,2,3 as monitor,not monitor, has camera
// if any child nodes not monitored set up a camera and inc count
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        // 1 : monitored 2: not monitored 3: has camera
        int count = 0;
        function<int(TreeNode*)> dfsMinCam = [&](TreeNode* node)->int {
            if(node == NULL) return 1;
            int l = dfsMinCam(node->left);
            int r = dfsMinCam(node->right);
            if(l == 1 && r == 1) return 2;
            if(l == 2 || r == 2) {count++; return 3;}
            return 1;
            // 11:2 12:3 13:1
            // 22:3 23:3
            // 33:1
        };
        int x = dfsMinCam(root);
        if(x == 2) count++;
        return count;
    }
};