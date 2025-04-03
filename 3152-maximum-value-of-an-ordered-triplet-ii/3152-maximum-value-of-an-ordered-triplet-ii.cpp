// Approach 1:
// we want to get max val of (x-y)*z; x,y,z->+ve
// use maxl for x, maxdiff for maxl-y, ans = maxdiff*z
// first update for z, then for y, then for x as z uses prev y(maxdiff), y uses prev x(maxl)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxl = 0, maxdiff = 0, ans = 0; // x,y,z
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            // first assume we have got z
            ans = max(ans,1LL*maxdiff*nums[i]); // nums[i] = z
            // then y
            maxdiff = max(maxdiff,1LL*maxl-nums[i]); // nums[i] = y
            // then finally x
            maxl = max(maxl,1LL*nums[i]); // nums[i] = x
        }
        return ans;
    }
};