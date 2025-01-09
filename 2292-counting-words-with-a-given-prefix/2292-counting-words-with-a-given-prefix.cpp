// Approach 2: Using Trie (Just counting prefix implementation)
class Solution {
public:
    struct Trie {
        struct node {
            int count = 0; // count for node's visit
            map<char,node*> next;
        };
        node* root = new node();
        void insert(string word) { // adds and increases count for nodes
            node* curr = root;
            for(auto c: word) {
                if(curr->next[c] == NULL) {curr->next[c] = new node;}
                curr = curr->next[c]; curr->count++;
            }
        }
        int prefixCount(string word) {
            node* curr = root;
            for(auto c: word) {
                if(curr->next[c] == NULL) {return 0;}
                curr = curr->next[c];
            }
            return curr->count;
        }

    };
    int prefixCount(vector<string>& words, string pref) {
        Trie trieds;
        for(auto w: words) {
            trieds.insert(w);
        }
        return trieds.prefixCount(pref);
    }
};