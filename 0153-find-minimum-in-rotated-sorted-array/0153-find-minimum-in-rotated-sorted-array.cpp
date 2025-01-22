// Approach 1: Using binary search
// find sorted half and take min in that sorted half then modify to check the other half
// use while(l <= r) if 2 ele, we want l or r to match and be same ele than skipping
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(nums[mid] <= nums[r]) {
                ans = min(ans,nums[mid]);
                r = mid-1;
            }
            else {
                ans = min(ans,nums[l]);
                l = mid+1;
            }
        }
        return ans;
    }
};