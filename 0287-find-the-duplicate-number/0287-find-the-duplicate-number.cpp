// Approach 1: Using inplace memeory
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            if(x >= n) {
                return n;
            }
            if(nums[x] < 0) {
                return x;
            }
            else {
                nums[x] *= -1;
            }
        }
        for(auto &it: nums) {
            it = abs(it);
        }
        return 0;
    }
};