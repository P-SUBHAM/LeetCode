// Aproach 1
// Apply Boyer-Moore Majority Vote:
// 1) Count and identify potential majority elements with a threshold of n/3.
// 2) Verify each candidate's count and return both verified majority elements if necessary.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans; int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && nums[i] != ele2) {cnt1 = 1; ele1 = nums[i];}
            else if(cnt2 == 0 && nums[i] != ele1) {cnt2 = 1; ele2 = nums[i];}
            else if(ele1 == nums[i]) {cnt1++;}
            else if(ele2 == nums[i]) {cnt2++;}
            else {cnt1--; cnt2--;}
        }
        cnt1 = cnt2 = 0;
        for(auto x: nums) {
            if(x == ele1) {cnt1++;}
            else if(x == ele2) {cnt2++;}
        }
        if(cnt1 > n/3) {ans.push_back(ele1);}
        if(cnt2 > n/3) {ans.push_back(ele2);}
        return ans;
    }
};