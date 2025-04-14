class BSTIterator {
private: stack<TreeNode*> st;
public:
    void pushALL(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushALL(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushALL(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
