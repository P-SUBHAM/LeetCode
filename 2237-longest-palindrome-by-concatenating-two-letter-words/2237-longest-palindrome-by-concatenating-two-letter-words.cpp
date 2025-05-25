class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0, midOddSame = 0;
        unordered_map<string,int> mp;
        for(auto word: words) {
            mp[word]++;
        }
        for(auto pair: mp) {
            string word = pair.first;
            int cnt = pair.second;
            if(word[0] == word[1]) {
                ans += (cnt - (cnt%2))*2;
                midOddSame = max(midOddSame,cnt%2); 
            }
            else if(word[0] < word[1]) {
                string rev = word; reverse(rev.begin(),rev.end());
                if(mp.find(rev) == mp.end()) continue;
                ans += min(mp[word],mp[rev])*2*2;
            }
        }
        return ans + midOddSame * 2;
    }
};