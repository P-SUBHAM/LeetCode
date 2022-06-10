class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i <= n; i++) {
            int x = i; int bits = 0;
            while(x > 0) {
                bits++;
                x = x&(x-1);
            }
            ans[i] = bits;
        }
        return ans;
    }
};