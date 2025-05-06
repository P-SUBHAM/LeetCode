// Approach 1: Brute
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(auto it: nums) {
            ans.push_back(nums[it]);
        }
        return ans;
    }
};