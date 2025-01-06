// Approach Kadane Algo
// sum = best(sum+a[i],a[i])
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0], sum = nums[0], n = nums.size();
        for(int i = 1; i < n; i++) {
            sum = max(sum+nums[i],nums[i]);
            best = max(best,sum);
        }
        return best;
    }
};