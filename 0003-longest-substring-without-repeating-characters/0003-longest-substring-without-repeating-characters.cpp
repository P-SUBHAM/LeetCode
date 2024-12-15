class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // using hashmap to store char,ind to count longest substring without rep char
        unordered_map<char,int> ind;
        int ans = 0, l = 0, r = 0;
        while(r < s.size()) {
            if(ind.find(s[r])==ind.end()) {
                ind[s[r]] = r;
                ans = max(ans,r-l+1);
                r++;
            }
            else {
                int l2 = ind[s[r]] + 1;
                while(l < l2) {
                    ind.erase(s[l]);
                    l++;
                }
                ind[s[r]] = r;
                r++;
            }
        }
        return ans;
    }
};