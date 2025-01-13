// Approach 1 logic x -> x-2 .... till (x ->2/1)
class Solution {
public:
    int F(int x) {
        return (x == 0) ? 0 : (x%2==0) ? 2: 1;
    }
    int minimumLength(string s) {
        map<char,int> mp;
        for(auto c: s) {
            mp[c]++;
        }
        int ans = 0;
        for(auto it: mp) {
            ans += F(it.second);
        }
        return ans;
    }
};