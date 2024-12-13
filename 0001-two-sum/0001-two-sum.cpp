class Solution {
public:
    // solving using hashmap
    vector<int> twoSumHashing(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mpp.find(target - nums[i]) == mpp.end()) {
                mpp[nums[i]] = i;
            }
            else {
                return {i, mpp[target - nums[i]]};
            }
        }
        return {};
    }
    // main twosum func
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSumHashing(nums,target);
    }
};