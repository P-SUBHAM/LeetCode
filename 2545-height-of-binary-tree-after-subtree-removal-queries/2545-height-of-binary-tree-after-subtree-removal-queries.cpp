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
    // Approach 1: It depends on the heights of the other nodes at the same level as the given node
    // find for a nodeToDel its [H] contribution and [max 2 height] at that [nodelev]
    unordered_map<int,multiset<int>> levelHeight;
    unordered_map<int,int> nodeLevel;
    unordered_map<int,int> nodeH;
    int preprocess(TreeNode* root, int lev) {
        nodeLevel[root->val] = lev;
        if(root->left == NULL && root->right == NULL) {
            levelHeight[lev].insert(0);
            if(levelHeight[lev].size() > 2) {
                levelHeight[lev].erase(levelHeight[lev].begin());
            }
            return nodeH[root->val] = 0;
        }
        int lh = 0, rh = 0;
        if(root->left != NULL)
            lh = preprocess(root->left,lev+1);
        if(root->right != NULL)
            rh = preprocess(root->right,lev+1);
        int ans = 1 + max(lh,rh);
        levelHeight[lev].insert(ans);
        if(levelHeight[lev].size() > 2) {
            levelHeight[lev].erase(levelHeight[lev].begin());
        }
        return nodeH[root->val] = ans;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        preprocess(root,0);
        int parH = *(--levelHeight[0].end());
        cout<<parH<<endl;
        vector<int> ans;
        for(auto nodeToDel: queries) {
            int lev = nodeLevel[nodeToDel];
            int delH = nodeH[nodeToDel];
            // cout<<nodeToDel<<" l:"<<lev<<" h:"<<delH<<endl; // dbg
            if(levelHeight[lev].size() == 1) {
                int ansH = parH - *levelHeight[lev].begin()-1;// because one top single edge also rem
                ans.push_back(ansH); continue;
            }
            int l = *levelHeight[lev].begin(), r = *(++levelHeight[lev].begin());
            if(delH <= l) {
                ans.push_back(parH);
            }
            else {
                ans.push_back(parH-r+l);
            }
        }
        return ans;
    }
};