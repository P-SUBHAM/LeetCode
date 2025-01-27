//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to check if two nodes are cousins in a tree
    bool isCousins(Node* root, int a, int b) {
        if (root == NULL) return false;
    
    int ap = -1, bp = -1, al = -1, bl = -1;

    // Helper function to find parent and level of a node
    function<void(Node*, int, int)> findCousinInfo = [&](Node* root, int level, int parent) {
        if (root == NULL) return;
        
        // If we found node 'a' or 'b', store its parent and level information
        if (root->data == a) {
            ap = parent;
            al = level;
        }
        if (root->data == b) {
            bp = parent;
            bl = level;
        }
        
        // If both nodes are found, we can stop the recursion
        if (ap != -1 && bp != -1) return;

        // Recursively search in left and right children
        findCousinInfo(root->left, level + 1, root->data);
        findCousinInfo(root->right, level + 1, root->data);
    };

    // Start the search for 'a' and 'b' starting from the root
    findCousinInfo(root, 0, -1);

    // Return false if one of the nodes is not found
    if (ap == -1 || bp == -1) {
        return false;
    }

    // The nodes are cousins if they are on the same level and have different parents
    return (al == bl) && (ap != bp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    Solution solution;
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        int x, y;
        scanf("%d ", &x);
        scanf("%d ", &y);
        cout << solution.isCousins(root, x, y) << endl;
        cout << "~" << endl;
    }
    return 1;
}
// } Driver Code Ends