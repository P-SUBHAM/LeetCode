// Approach 1: Binary search 
// check if right sorted or left sorted and update min accordingly
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int ans = nums[0];
        while(low <= high) { // = is imp here
            while(low<=high && nums[low] == nums[high]) { // != is imp to avoid bad access outside loop
                ans = min(ans,nums[low]);
                low++;high--;
            }
            if(low>high) break; // if u use low<=high above need this
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