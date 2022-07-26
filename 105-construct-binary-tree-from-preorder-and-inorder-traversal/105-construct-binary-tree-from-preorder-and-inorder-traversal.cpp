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
    int search(vector<int> inorder, int l, int r, int x) {
        for(int i = l; i <= r; i++) {
            if(inorder[i] == x) {
                return i;
            }
        }
        return -1;
    }
    int idx = 0;
    TreeNode* buildPreIn(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        
        
        if(l > r) {
            return NULL;
        }
        
        // if(idx == preorder.size()) return NULL;
        int curr = preorder[idx];
        idx++;
        TreeNode* root = new TreeNode(curr);
        if(l == r) {
            return root;
        }
        int pos = search(inorder,l,r,curr);
        root->left = buildPreIn(preorder,inorder,l,pos-1);
        root->right = buildPreIn(preorder,inorder,pos+1,r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildPreIn(preorder,inorder,0,preorder.size()-1);
    }
};