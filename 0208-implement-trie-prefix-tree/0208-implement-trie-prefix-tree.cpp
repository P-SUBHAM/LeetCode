class Trie {
public:
    struct TrieNode {
        char val; // node val for debugging 
        int count; // count starting with
        int end; // count ending at
        TrieNode *next[26]; // child nodes
    };

    TrieNode *root;

    TrieNode *getNode(int ind) {
        TrieNode* node = new TrieNode;
        node->val = 'a' + ind;
        node->count = node->end = 0;
        for(int i = 0; i < 26; i++) {
            node->next[i] = NULL;
        }
        return node;
    }

    Trie() {
        root = getNode('/' - 'a');
    }
    
    void insert(string word) {
        int i = 0, n = word.size();
        auto curr = root;
        while(i < n) {
            int ind = word[i] - 'a';
            if(curr->next[ind] == NULL) {
                curr->next[ind] = getNode(word[i]-'a');
            }
            curr = curr->next[ind];
            curr->count += 1;
            i++;
        }
        curr->end += 1;
    }
    
    bool search(string word) {
        int i = 0, n = word.size();
        auto curr = root;
        while(i < n) {
            int ind = word[i] - 'a';
            if(curr->next[ind] == NULL) {
                return false;
            }
            curr = curr->next[ind];
            i++;
        }
        return curr->end != 0;
    }
    
    bool startsWith(string prefix) {
        int i = 0, n = prefix.size();
        auto curr = root;
        while(i < n) {
            int ind = prefix[i] - 'a';
            if(curr->next[ind] == NULL) {
                return false;
            }
            curr = curr->next[ind];
            i++;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */