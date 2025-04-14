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

class Solution {
public:
    struct bstIteratorLeft {
        stack<TreeNode*> st;
        void pushAll(TreeNode* root) {
            while(root != NULL) {
                st.push(root); root=root->left;
            }
        }
        bstIteratorLeft(TreeNode* root) {
            pushAll(root);
        }
        // Type operator++(int);  // Post-increment, the `int` is just a dummy
        int operator++() { // pre-increment
            if(st.empty()) return -1;
            TreeNode *temp = st.top(); st.pop();
            pushAll(temp->right);
            return temp->val;
        }
        int operator*() {
            return st.top()->val;
        }
    };
    struct bstIteratorRight {
        stack<TreeNode*> st;
        void pushAll(TreeNode* root) {
            while(root != NULL) {
                st.push(root); root=root->right;
            }
        }
        bstIteratorRight(TreeNode* root) {
            pushAll(root);
        }
        int operator--(int) {
            if(st.empty()) return -1;
            TreeNode *temp = st.top(); st.pop();
            pushAll(temp->left);
            return temp->val;
        }
        int operator*() {
            return st.top()->val;
        }
    };
    bool findTarget(TreeNode* root, int k) {
        bstIteratorLeft left(root);
        bstIteratorRight right(root);
        while(*left < *right) {
            if(*left + *right == k) return true;
            else if(*left + *right < k)  ++left;
            else  right--;
        }
        return false;
    }
};
