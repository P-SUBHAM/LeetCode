/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*> parent;
    vector<int> ans;
    void distanceKUtil(TreeNode* target, int k) {
        if(k < 0) {
            return;
        }
        if(target == 0) {
            return;
        }
        if(k == 0) {
                ans.push_back(target->val);
        }
        distanceKUtil(target->left,k-1);
        distanceKUtil(target->right,k-1);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent.clear();
        ans.clear();
        queue<TreeNode*> qu;
        qu.push(root);
        parent[root] = NULL;
        while(!qu.empty()) {
            TreeNode* node = qu.front();
            qu.pop();
            if(node->left != NULL) {
                qu.push(node->left);
                parent[node->left] = node;
            }
            if(node->right != NULL) {
                qu.push(node->right);
                parent[node->right] = node;
            }
        }
        distanceKUtil(target,k);
        TreeNode* child = target;
        TreeNode* parentnode;
        int lev = k;
        while(lev > 0 && parent[child] != NULL) {
            lev--;
            
            
            parentnode = parent[child];
            if(lev == 0) {
                ans.push_back(parentnode->val);
                break;
            }
            if(parentnode->left == child) {
                distanceKUtil(parentnode->right,lev-1);
            }
            if(parentnode->right == child) {
                distanceKUtil(parentnode->left,lev-1);
            }
            child = parentnode;
        }
        return ans;
        
    }
};