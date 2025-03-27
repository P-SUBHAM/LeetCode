class Solution {
public:
    struct compm {
        bool operator()(vector<int> &v1, vector<int> &v2) {
            return v1[1] < v2[1];
        }
    };
    
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
                // cout<<ans<<" "; // dbg
            }
            // cout<<endl; // dbg
            // cout<<x<<":"<<ans<<","<<sz<<endl; // dbg
            return ans;
        }
    };
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> offlineQuery;
        int qSz = queries.size();
        int n = nums.size();
        vector<int> ans(qSz);
        for(int i = 0; i < qSz; i++) {
            int x = queries[i][0], m = queries[i][1], ind = i;
            offlineQuery.push_back({x,m,ind});
        }
        sort(nums.begin(),nums.end());
        sort(offlineQuery.begin(),offlineQuery.end(),compm());
        BinaryBitTrie trie;
        int j = 0;
        for(auto query: offlineQuery) {
            int x = query[0], m = query[1], ind = query[2];
            while(j < n && nums[j] <= m) {
                trie.insert(nums[j]); j++;
            }
            int maxXorV = trie.xorMax(x);
            ans[ind] = maxXorV;
        }
        return ans;
    }
};