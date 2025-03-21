// Approach 1: 0 to 2^n-1 will have correct representation 
// sorting nums and checking which number is missing in range
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> v;
        for(auto it: nums) {
            int no = 0;
            for(int i = 0; i < n; i++) { // "101" [0][1][2] 
                if(it[i]=='1') {
                    no += 1<<(n-1-i);
                }
            }
            v.push_back(no);
        }
        sort(v.begin(),v.end());
        // for(auto it: v) cout<<it<<" "; cout<<endl;
        int missno = -1; // convert back into binary string
        for(int i = 0; i < n; i++) { // n+1 no's
            if(v[i]!=i) {
                missno = i; break;
            }
        }
        if(missno==-1) missno = n; // 0->n-1 all bin str present so choose n
        string ans = "";
        for(int i = n-1; i >= 0; i--) { // "101" [0][1][2] 
            if((missno>>i)&1==1) {
                ans += "1";
            }
            else {
                ans += "0";
            }
        }
        return ans;
    }
};

// Approach tle1: Brute (TLE)
// generate all 2^n combination, remove occurences and select a leftover string
// T: 2^n + 2^n-1+..+1
class SolutionTle1 {
public:
    set<string> rec(int n) {
        if(n==1) {
            return {"0","1"};
        }
        set<string> n_1 = rec(n-1);
        set<string> ans;
        for(auto it: n_1) {
            ans.insert(it+"0"); 
            ans.insert(it+"1");
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<string> st = rec(n);
        for(auto str: nums) {
            st.erase(str);
        }
        return *st.begin();
    }
};