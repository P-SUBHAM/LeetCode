/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Approach 1: Basic Level ordered traversal using queue
// while !qu.empty() iterate for size of qu pushing the current level val, and pushing in the child level into queue
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {}; 
        vector<vector<int>> ans;
        queue<Node*> qu; qu.push(root);
        while(!qu.empty()) {
            vector<int> v;
            int sz = qu.size();
            for(int i = 0; i < sz; i++) {
                auto node = qu.front(); qu.pop();
                v.push_back(node->val);
                for(auto child: node->children) qu.push(child);
            }
            ans.push_back(v);
        }
        return ans;
    }
};