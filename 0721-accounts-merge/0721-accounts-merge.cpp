class Solution {
public:
    struct dsu {
        vector<int> parent;
        vector<int> rank;
        dsu(int n) {
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i = 0; i <= n; i++) { // make set
                make_set(i);
            }
        }
        void make_set(int x) {
            parent[x] = x;
        }
        int find_set(int x) {
            if(parent[x] == x) {
                return x;
            }
            return parent[x] = find_set(parent[x]);
        }
        void union_set(int x, int y) {
            int parentX = find_set(x);
            int parentY = find_set(y);
            if(parentX != parentY) { // merge by rank
                if(rank[parentX] < rank[parentY]) { // merge px to py
                    parent[parentX] = parentY;
                }
                else if(rank[parentX] > rank[parentY]) { // merge py to px
                    parent[parentY] = parentX;
                }
                else {
                    parent[parentY] = parentX;
                    rank[parentX]++;
                }
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // map mail to unique id
        int emailCounter = 0;
        unordered_map<string,int> emailMap;
        for(auto account: accounts) {
            int accLen = account.size();
            for(int i = 1; i < accLen; i++) {
                string mail = account[i];
                if(emailMap.find(mail) == emailMap.end()) {
                    emailMap[mail] = ++emailCounter;
                }
            }
        }

        // merge same mail together
        dsu emailDsu(emailCounter);
        for(auto account: accounts) {
            int accLen = account.size();
            for(int i = 1; i < accLen - 1; i++) {
                string mail1 = account[i];
                string mail2 = account[i+1];
                int uid = emailMap[mail1];
                int vid = emailMap[mail2];
                // union mail1 mail2
                emailDsu.union_set(uid,vid);
            }
        }

        unordered_map<int,string> accountOwner;
        for(auto account: accounts) {
            string owner = account[0];
            string mail = account[1];
            int emailid = emailMap[mail];
            int parentid = emailDsu.find_set(emailid);
            accountOwner[parentid] = owner;
        }

        unordered_map<int,set<string>> accountMap;
        for(auto pair: emailMap) {
            int emailid = pair.second;
            string mail = pair.first;
            int parentid = emailDsu.find_set(emailid);
            accountMap[parentid].insert(mail);
        }

        vector<vector<string>> mergedAccountsList;
        for(auto pair: accountMap) {
            int parentid = pair.first;
            auto accountSet = pair.second;
            string owner = accountOwner[parentid];
            vector<string> account;
            account.push_back(owner);
            for(auto mail: accountSet) {
                account.push_back(mail);
            }
            mergedAccountsList.push_back(account);
        }
        return mergedAccountsList;
    }
};