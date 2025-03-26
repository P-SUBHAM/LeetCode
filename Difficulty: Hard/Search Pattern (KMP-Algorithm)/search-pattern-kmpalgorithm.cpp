//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // prefix[j-1] gives index to next check 0 based i.e all prev ele are already prefix matched
    vector<int> prefix_func(string s) {
        int n = s.size();
        vector<int> prefix(n,0);
        for(int i = 1; i < n; i++) {
            int j = prefix[i-1];
            while(j > 0 && s[i]!=s[j]) {
                j = prefix[j-1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            prefix[i] = j;
        }
        return prefix;
    }

    //kmp
    vector<int> KMP_func(string a, string b) { // check b(part) in a(main)
        int pos = -1;
        vector<int> prefix = prefix_func(b);
        vector<int> occur;
        int i = 0, j = 0;
        // assume aabaa is matched in a j=5->pre[4]=2
        while(i < a.size()) { // while loop preferable
            if(a[i] == b[j]) {
                i++; j++;
            }
            else {
                if(j > 0) {
                    j = prefix[j-1];
                }
                else {
                    i++;
                }
            }
            if(j == b.size()) {
                pos = i - b.size();
                occur.push_back(pos);
                j = prefix[j-1];
            }
        }
        return occur;
    }
    vector<int> KMP_Z_func(string txt, string pat) {
        string comb = pat + "$" + txt;
        // cout<<comb<<endl;
        vector<int> prefix = prefix_func(comb);
        int patSz = pat.size();
        vector<int> pos;
        for(int i = 0; i < comb.size(); i++) {
            // cout<<prefix[i]<<" ";
            if(prefix[i] == patSz) {
                pos.push_back(i-patSz+1-patSz-1);
            }
        } // cout<<endl;
        return pos;
    }
    vector<int> search(string& pat, string& txt) {
        // vector<int> ans = KMP_func(txt,pat);
        vector<int> ans = KMP_Z_func(txt,pat);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends