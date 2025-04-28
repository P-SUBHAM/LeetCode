// Approach 1: 2 ptr
// keep increasing r as long as valid (r < n && (sum+nums[r])*(r-l+1) < k)
// then decrease l and count;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size(), l = 0, r = 0;
        long long sum = 0, ans = 0;
        while(l < n) {
            if(r < n && 1ll*(sum+nums[r])*(r-l+1) < k) {
                sum += nums[r]; r++;
            }
            else {
                // cout<<r-l<<endl;
                ans += (r-l); 
                sum -= nums[l];
                l++;
            }
        }
        return ans;
    }
};