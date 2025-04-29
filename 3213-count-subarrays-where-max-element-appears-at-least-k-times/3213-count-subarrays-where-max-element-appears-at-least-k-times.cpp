// Approach 1: 2ptr
// while u can expand expand, once valid shrink and calc no of subarrays
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxv = *max_element(nums.begin(),nums.end());
        long long ans = 0, l = 0, r = 0, n = nums.size(), cnt = 0;
        // while(r < n) {
        //     if(cnt < k) {
        //         if(nums[r++] == maxv) {
        //             cnt++;
        //         }
        //     }
        //     while(cnt == k) { // 3 3 1 4
        //         ans += n-1-(r-1)+1;
        //         if(nums[l] == maxv) cnt--;
        //         l++;
        //     }
        // }
        while(r < n || cnt == k) {
            if (cnt == k) { // 3 3 1 4
                ans += n-1-(r-1)+1;
                if(nums[l] == maxv) cnt--;
                l++;
            }
            else if(cnt < k) {
                if(nums[r++] == maxv) {
                    cnt++;
                }
            }
        }
        return ans;
    }
};