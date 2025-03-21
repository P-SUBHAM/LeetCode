// Approach 1: using dfs with Trie
// create Trie and add all the words
// now do dfs, send the appropriate trie node, word found in dfs till now
// based on the next node in trie node it will traverse the grid, before exiting dfs mark the vis as false for next iter of i,j or u can pass new vis each time to dfs function
// Also used lamda function, prefer unordered_map
struct Trie {
    struct Node{
        int end;
        unordered_map<char,Node*> next;
    };
    Node *root = new Node();
    void insert(string s) {
        auto it = root;
        for(char c: s) {
            if(it->next[c]==0) it->next[c] = new Node();
            it = it->next[c];
        }
        it->end++; // increases one end here
    }
    bool search(string s) {
        auto it = root;
        for(char c: s) {
            if(it->next[c]==0) return false;
            it = it->next[c];
        }
        return it->end > 0; // check 1 or more end
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(auto s: words) {
            t.insert(s);
        }
        int m = board.size(), n = board[0].size();
        unordered_set<string> ans; vector<vector<bool>> vis(m,vector<bool>(n,false));
        function<void(int r,int c,Trie::Node* node, string word)> dfs = [&](int r,int c,Trie::Node* node, string word) {
            if(r<0||c<0||r>=m||c>=n||vis[r][c]||node->next[board[r][c]]==0) {
                return;
            }
            char ch = board[r][c];
            vis[r][c] = true;
            node = node->next[ch];
            word += ch;
            if(node->end) ans.insert(word);
            dfs(r+1,c,node,word);
            dfs(r,c+1,node,word);
            dfs(r-1,c,node,word);
            dfs(r,c-1,node,word);
            vis[r][c] = false;
        };
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(i,j,t.root,"");
            }
        }
        vector<string> res;
        for(auto it: ans) {
            res.push_back(it);
        }
        return res;
    }
};