//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User function Template for C++

/*
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
    Node* mapRootToParent(unordered_map<Node*,Node*> &mp, 
    Node* root, int target) {
        mp[root] = NULL;
        Node* targetAddress = NULL;
        
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()) {
            auto node = qu.front(); qu.pop();
            if(node->left != NULL) {
                qu.push(node->left);
                mp[node->left] = node;
            }
            if(node->right != NULL) {
                qu.push(node->right);
                mp[node->right] = node;
            }
            if(node->data == target) {
                targetAddress = node;
            }
        }
        
        return targetAddress;
    }
    int levelOrderBFS(Node* targetAddress,
    unordered_map<Node*,Node*> &mp) {
        int depth = -1;
        queue<Node*> qu;
        qu.push(targetAddress);
        unordered_map<Node*,bool> vis;
        vis[targetAddress] = true;
        
        while(!qu.empty()) {
            int quSize = qu.size();
            depth++;
            while(quSize--) {
                auto node = qu.front(); qu.pop();
                if(node->left != NULL && !vis[node->left]) {
                    qu.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right != NULL && !vis[node->right]) {
                    qu.push(node->right);
                    vis[node->right] = true;
                }
                auto parentNode = mp[node];
                if(parentNode != NULL && !vis[parentNode]) {
                    qu.push(parentNode);
                    vis[parentNode] = true;
                }
            }
        }
        return depth;
    }
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*,Node*> mp;
        
        Node* targetAddress;
        targetAddress = mapRootToParent(mp,root,target);
        
        int ans;
        ans = levelOrderBFS(targetAddress,mp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends