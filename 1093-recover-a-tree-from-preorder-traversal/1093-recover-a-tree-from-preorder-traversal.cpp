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
// Approach 1: Tree recursion to recover and build tree
// Convert string sequence to Node(depth,val)
// start with depth of node, if node avaialable choose it, then recover left and right subtree
class Solution {
public:
    int node;
    // returns receovered tree at depth d 
    TreeNode* recover(vector<pair<int,int>> &vp, int d) { // Node(depth,val)
        if(node==vp.size()) return NULL; // all nodes used
        if(vp[node].first!=d) return NULL; // node of depth d 
        TreeNode* root = new TreeNode(vp[node].second); node++;
        root->left = recover(vp,d+1);
        root->right = recover(vp,d+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        vector<pair<int,int>> vp;
        int d = 0, val = 0;
        for(int i = 0; i < n; i++) {
            char ch = traversal[i];
            if(isdigit(ch)) {
                val *= 10;
                val += ch-'0';
            }
            else {
                if(traversal[i-1]=='-') {
                    d++;
                }
                else {
                    vp.push_back({d,val});
                    d = 1; val = 0;
                }
            }
        } vp.push_back({d,val}); // for last node
        // for(auto it: vp) {
        //     cout<<it.first<<":"<<it.second<<endl;
        // }
        node = 0;
        TreeNode* ans = recover(vp,0); // start with 0 depth
        return ans;
    }
};