// Approach 1
// 1. check decrement cnt, if cnt = 1 then 0-part, part+1-end
class Solution {
public:
    bool check(vector<int>& nums) {
        int dec_cnt = 0, v;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] > nums[i]) {
                dec_cnt++; v = nums[i-1];
            }
        }
        if(dec_cnt==0) return true;
        if(dec_cnt==1) return v >= nums.back() && nums[0] >= nums.back();
        return false;
    }
};