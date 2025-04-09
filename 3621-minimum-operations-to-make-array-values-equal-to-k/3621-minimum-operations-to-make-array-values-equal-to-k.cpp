// Approach 1: logic
// check all >= k && return no of distinct numbers > k 
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0] < k) return -1; // all num >= k
        int ans = (nums[0] > k);
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) {
                ans++;
            }
        }
        return ans;
    }
};