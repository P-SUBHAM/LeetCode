// Approach 1 Kadanes algo 
// once with +ve,-ve find max sum and abs(min sum(-ve)) and return the max
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sump = nums[0], sumn = nums[0], ansp = nums[0], ansn = nums[0], ans = abs(nums[0]), n = nums.size();
        for(int i = 1; i < n; i++) {
            sump = max(sump+nums[i],nums[i]);
            sumn = min(sumn+nums[i],nums[i]);
            ansp = max(ansp,sump);
            ansn = min(ansn,sumn);
            ans = max(abs(ansp),abs(ansn));
        }
        return ans;
    }
};