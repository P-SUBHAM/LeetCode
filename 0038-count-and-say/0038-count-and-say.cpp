// Approach 1: Recursion
class Solution {
public:
    string nextCountAndSay(string s) {
        int freq = 1, lastEle = s[0], n = s.size();
        string ans = "";
        for(int i = 1; i < n; i++) {
            if(s[i] == lastEle) {
                freq++;
            }
            else {
                ans += to_string(freq) + string(1,lastEle);
                freq = 1; lastEle = s[i];
            }
        }
        ans += to_string(freq) + string(1,lastEle);
        return ans;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        return nextCountAndSay(countAndSay(n-1));
    }
};