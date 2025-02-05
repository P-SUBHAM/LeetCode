// Approach 1: 2 pointer
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), ans = 0, zerocnt = 0;
        while(r < n) {
            if(nums[r] == 1) {
                r++; ans = max(ans,r-l);
            }
            else {
                if(zerocnt < k) {
                    r++; zerocnt++; ans = max(ans,r-l);
                }
                else {
                    if(nums[l] == 0) zerocnt--;
                    l++;
                }
            }
        }
        return ans;
    }
};