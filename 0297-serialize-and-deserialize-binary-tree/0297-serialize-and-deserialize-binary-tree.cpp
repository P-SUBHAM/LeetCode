/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Use Preorder traversal
    // Encodes a tree to a single string.
    int ans = 0;
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "#";
        }
        bool flag = false;
        if(ans == 0) {
            flag = true;
        }
        ans++;
        string ser = to_string(root->val) + "," 
        + serialize(root->left) + "," 
        + serialize(root->right);
        if(flag == true) {
          cout<<ser<<"\n";
        }
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0, N = (int)data.size();
        function<TreeNode*()> deserializef = [&]() -> TreeNode* {
            if (i >= N || data[i] == '#') {
                i += 2; // Move past '#' and the comma
                return (TreeNode*)NULL;
            }

            // Extract the node value
            string valStr;
            while (i < N && data[i] != ',') {
                valStr += data[i++];
            }
            i++; // Skip the comma

            int nodeVal = stoi(valStr);
            TreeNode *root = new TreeNode(nodeVal);
            root->left = deserializef();
            root->right = deserializef();
            return root;
        };

        return deserializef();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));