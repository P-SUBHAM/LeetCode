// practice
class Trie {
public:
    struct node {
      bool end = false;
      unordered_map<char,node*> next;
    };
    // Trie() {
        
    // }
    node *root = new node;
    void insert(string word) {
      auto it = root;
      for(auto ch: word) {
        if(it->next[ch]==NULL) {
          it->next[ch] = new node;
        }
        it = it->next[ch];
      }
      it->end = true;
    }
    bool search(string word) {
      auto it = root;
      for(auto ch: word) {
        if(it->next[ch]==NULL)
          return false;
        it = it->next[ch];
      }
      return it->end;
    }
    
    bool startsWith(string prefix) {
      auto it = root;
      for(auto ch: prefix) {
        if(it->next[ch]==NULL)
          return false;
        it = it->next[ch];
      }
      return it != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// ---------

// APPROACH 2 : Simpler Trie Implementation
class Trie2 {
public:
    struct node{
        bool end = false;
        node* next[26] = {};
    };
    node *root = new node();
    void insert(string word) {
        auto it = root;
        for(char c: word) {
            int ind = c - 'a';
            if(it->next[ind] == NULL) {
                it->next[ind] = new node();
            }
            it = it->next[ind];
        }
        it->end = true;
    }
    bool search(string word) {
        auto it = root;
        for(char c: word) {
            int ind = c - 'a';
            if(it->next[ind] == NULL) {return false;}
            it = it->next[ind];
        }
        return it->end;
    }
    bool startsWith(string prefix) {
        auto it = root;
        for(int i = 0; i < prefix.size(); i++) {
            int ind = prefix[i] - 'a';
            if(it->next[ind] == NULL) {return false;}
            it = it->next[ind];
        }
        return it;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// APPROACH 1
// class Trie {
// public:
//     struct TrieNode {
//         char val; // node val for debugging 
//         int count; // count starting with
//         int end; // count ending at
//         TrieNode *next[26]; // child nodes
//     };

//     TrieNode *root;

//     TrieNode *getNode(int ind) {
//         TrieNode* node = new TrieNode;
//         node->val = 'a' + ind;
//         node->count = node->end = 0;
//         for(int i = 0; i < 26; i++) {
//             node->next[i] = NULL;
//         }
//         return node;
//     }

//     Trie() {
//         root = getNode('/' - 'a');
//     }
    
//     void insert(string word) {
//         int i = 0, n = word.size();
//         auto curr = root;
//         while(i < n) {
//             int ind = word[i] - 'a';
//             if(curr->next[ind] == NULL) {
//                 curr->next[ind] = getNode(word[i]-'a');
//             }
//             curr = curr->next[ind];
//             curr->count += 1;
//             i++;
//         }
//         curr->end += 1;
//     }
    
//     bool search(string word) {
//         int i = 0, n = word.size();
//         auto curr = root;
//         while(i < n) {
//             int ind = word[i] - 'a';
//             if(curr->next[ind] == NULL) {
//                 return false;
//             }
//             curr = curr->next[ind];
//             i++;
//         }
//         return curr->end != 0;
//     }
    
//     bool startsWith(string prefix) {
//         int i = 0, n = prefix.size();
//         auto curr = root;
//         while(i < n) {
//             int ind = prefix[i] - 'a';
//             if(curr->next[ind] == NULL) {
//                 return false;
//             }
//             curr = curr->next[ind];
//             i++;
//         }
//         return true;
//     }
// };