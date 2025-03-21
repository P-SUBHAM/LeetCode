// Approach 1: 2ptr
// Use Auxillary ans array
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int l = 0, r = n-1;
        vector<int> ans(n,pivot);
        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                ans[l++] = nums[i];
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] > pivot) {
                ans[r--] = nums[i];
            }
        }
        return ans;
    }
};