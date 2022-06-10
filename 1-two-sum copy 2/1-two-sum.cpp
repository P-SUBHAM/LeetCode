class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> pos;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(pos.find(target-nums[i])!=pos.end()) {
                return {pos[target-nums[i]],i};
            }
            pos[nums[i]] = i;
        }
        return {-1,-1};
    }
};