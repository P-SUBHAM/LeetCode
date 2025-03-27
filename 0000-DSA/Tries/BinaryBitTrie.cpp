struct BinaryBitTrie {
    vector<bool> getBinaryBits(int x) {
        vector<bool> s;
        for(int i = 31; i >= 0; i--) {
            int ithBit = ((x >> i)&1);
            s.push_back(ithBit);
        }
        return s;
    }
    struct node {
        bool end = false;
        node* next[2] = {}; // 0 1 // IMP define like this
    };
    node *root = new node;
    int sz = 0;
    void insert(int x) {
        vector<bool> s = getBinaryBits(x);
        auto it = root;
        for(int i = 0; i < 32; i++) {
            bool bit = s[i];
            if(it->next[bit] == NULL) {
                it->next[bit] = new node;
            }
            it = it->next[bit];
        }
        it->end = true;
        sz++;
        // cout<<"ins:"<<x<<endl;
    }
    int xorMax(int x) {
        if(sz == 0) return -1;
        vector<bool> s = getBinaryBits(x);
        auto it = root;
        int ans = x;
        for(int i = 0; i < 32; i++) {
            bool bit = s[i];
            bool altBit = (bit^1);
            if(it->next[altBit] != NULL) {
                it = it->next[altBit];
                ans ^= (altBit<<(31-i));
            }
            else if(it->next[bit] != NULL) {
                it = it->next[bit];
                ans ^= (bit<<(31-i));
            }
            else {
                return -1;
            }
        }
        return ans;
    }
};