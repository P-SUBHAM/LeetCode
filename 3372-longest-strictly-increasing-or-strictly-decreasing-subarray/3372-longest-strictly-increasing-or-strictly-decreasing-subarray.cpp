// Approach 1:
// whenever pos of +, increase, pos of - decrease, equal then reset
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, incr = 1, decr = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                incr++; decr=1; ans = max(ans,incr);
            }
            else if(nums[i] < nums[i-1]) {
                decr++; incr = 1; ans = max(ans,decr);
            }
            else {
                incr = decr = 1;
            }
        }
        return ans;
    }
};