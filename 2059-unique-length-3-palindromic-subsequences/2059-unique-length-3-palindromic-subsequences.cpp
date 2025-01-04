// Approach 1 using set
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        map<char,int> left, right;
        left[s[0]]++; 
        for(int k = n-1; k >= 2; k--) {
            right[s[k]]++;
        }
        // set<string> ans;
        int cnt = 0;
        vector<vector<bool>> seen(26,vector<bool>(26,false));
        for(int j = 1; j < n-1; j++) {
            for(char i = 'a'; i <= 'z'; i++) {
                if(left[i] && right[i]) {
                    seen[i-'a'][s[j]-'a'] = true;
                    // string x = string(1,i) + s[j] + string(1,i);
                    // ans.insert(x);
                }
            }
            left[s[j]]++;
            right[s[j+1]]--;
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(seen[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};