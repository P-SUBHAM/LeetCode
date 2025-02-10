// Approach 1: Brute
// check indexes where Num exists
// itterate left from Num index if alpha then modify
// finally reconstruct
class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        int num = 0; vector<int> ind;
        for(int i = 0 ; i < n; i++) {
            if(isdigit(s[i])) {
                ind.push_back(i);
                num++;
            }
        }
        for(auto it: ind) {
            for(int j = it; j >= 0; j--) {
                if(isalpha(s[j])) {
                    s[j] = '*'; break;
                }
            }
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(isalpha(s[i])) {
                ans += s[i];
            }
        }
        return ans;
    }
};