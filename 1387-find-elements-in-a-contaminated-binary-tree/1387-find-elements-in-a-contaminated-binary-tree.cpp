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
// Approach 1: recover: if -1 set to 0, then update left and right child if exists
// search recursively in entire tree
class FindElements {
public:
    TreeNode* root;
    void recover(TreeNode* root) {
        if(root==NULL) return;
        if(root->val==-1) root->val = 0; //For first time when all val are -1
        if(root->left!=NULL) root->left->val = 2*root->val+1; // fix left child
        if(root->right!=NULL) root->right->val = 2*root->val+2;//fix right child
        recover(root->left);
        recover(root->right);
    }
    FindElements(TreeNode* root_) { // recover the tree
        root = root_;
        recover(root);
    }
    bool treeFind(TreeNode* root, int target) {
        if(root==NULL) return false;
        if(root->val==target) return true;
        return treeFind(root->left,target) || treeFind(root->right,target);
    }
    bool find(int target) { // search in recovered tree
        return treeFind(root,target);
    }
    /*  0
        1 2
        3 4 5 6
        7 8 9 10 11 12 13 14
    */
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */