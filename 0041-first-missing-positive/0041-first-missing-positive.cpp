// APPROACH 3:
// answer lies between 1 to n, convert outside range to n+1()
// Normalize array to range [1, n+1], mark indices for present values using negatives, and find first unmarked index.
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(auto &x: nums) {if(x < 1 or x > n) {x = n+1;}}
        // for(auto x: nums) cout<<x<<" "; cout<<endl; //get into 1 to n,n+1 range
        for(auto x: nums) {if(abs(x) >= 1 && abs(x) <= n) {nums[abs(x)-1] = -1*abs(nums[abs(x)-1]);}}
        // for(auto x: nums) cout<<x<<" "; cout<<endl; // marked -ve 
        for(int i = 1; i <= n; i++) {
            if(nums[i-1] > 0) {
                return i;
            }
        }
        return n+1;
    }
};