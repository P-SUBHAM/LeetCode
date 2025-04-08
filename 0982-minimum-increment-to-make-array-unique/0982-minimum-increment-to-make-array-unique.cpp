// Approach 1: Logic
// sort the arr, every ele should be atleast euqal to nums[i-1]+1 find the diff
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // for(auto it: nums) cout<<it<<" "; cout<<endl;
        int ans = 0, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i-1]+1) {
                ans += nums[i-1]+1-nums[i];
                nums[i] = nums[i-1]+1;
            }
        }
        return ans;
    }
};