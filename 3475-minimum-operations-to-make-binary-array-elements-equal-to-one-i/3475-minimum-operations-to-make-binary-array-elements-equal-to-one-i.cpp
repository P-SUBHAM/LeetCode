// Approach 1: Sliding window technique
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i <= n - 3; i++) {
            if(nums[i] == 1) continue;
            nums[i]^=1, nums[i+1]^=1, nums[i+2]^=1;
            cnt++;
        }
        return (nums[n-1] == 1 && nums[n-2] == 1)?cnt:-1;
    }
};