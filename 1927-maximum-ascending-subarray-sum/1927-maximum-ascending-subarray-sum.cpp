// Approach 1:
// 1. Keep adding to sum and taking max as long as we get a larger no
// 2. if we get a smaller no reset sum to it, no need for taking max as it's smaller than prev ele which already has contributed to global max sum
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                sum += nums[i];
                ans = max(ans,sum);
            }
            else {
                sum = nums[i];
            }
        }
        return ans;
    }
};