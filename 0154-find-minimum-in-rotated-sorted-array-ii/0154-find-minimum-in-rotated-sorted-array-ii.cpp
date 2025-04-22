// Approach 1: Binary search 
// check if right sorted or left sorted and update min accordingly
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int ans = nums[0];
        while(low <= high) {
            while(low<high && nums[low] == nums[high]) {
                ans = min(ans,nums[low]);
                low++;high--;
            }
            int mid = (low+high)/2;
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            if(nums[mid] <= nums[high]) {
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
            else {
                ans = min(ans,nums[low]);
                low = mid+1;
            }
        }
        return ans;
    }
};