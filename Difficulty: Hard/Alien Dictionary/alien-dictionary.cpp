//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void worddiff(string &w1, string &w2, char &ch1, char &ch2) {
        for(int i = 0; i < w1.size() && i < w2.size(); i++) {
            if(w1[i]!=w2[i]) {
                ch1 = w1[i], ch2 = w2[i]; return;
            }
        }
        if(w1.size() > w2.size()) {ch1 = '-'; return; }
        ch1 = '0', ch2 = '0'; return;
    }
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<char>> adj(128);
        vector<int> indeg(128);
        unordered_set<char> st;
        unordered_set<char> st2;
        
        for(int i = 0; i < n - 1; i++) {
            string w1 = words[i], w2 = words[i+1];
            for(auto it: w1) st.insert(it);
            for(auto it: w2) st.insert(it);
            char u, v;
            worddiff(w1,w2,u,v);
            if(u=='0') continue;
            if(u=='-') return ""; // imp abc ab not possible
            st2.insert(u); st2.insert(v);
            adj[u].push_back(v);
            indeg[v]++;
        }
        if(n == 1) {
            for(auto it: words[0]) {
                st.insert(it); st2.insert(it); // edge 
            }
        }
        queue<char> qu; // topo sort
        for(auto ch: st2) {
            if(indeg[ch] == 0) {
                qu.push(ch);
            }
        }
        string ans = "";
        while(!qu.empty()) {
            auto node = qu.front(); qu.pop(); ans += node;
            for(auto nei: adj[node]) {
                if(--indeg[nei] == 0) {
                    qu.push(nei);
                }
            }
        }
        
        for(auto it: st) {
            // cout<<it<<" ";
            if(ans.find(it)==string::npos) {
                ans += string(1,it);
            }
        }
        // cout<<ans<<endl;
        for(auto it: st2) {
            if(indeg[it] > 0) {
                // cout<<"empty";
                return "";
            }
            // else if(ans.find(it)==string::npos) {
            //     ans += it;
            // }
        }
        // dddc a ad ab b becd cded
        // abc ab
        // wnlb
        return ans;
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends