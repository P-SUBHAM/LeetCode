class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < (1<<n); i++) {
            int tempXor = 0;
            for(int j = 0; j < n; j++) {
                if((i>>j)&1) {
                    tempXor ^= nums[j];
                }
            }
            ans += tempXor;
        }
        return ans;
    }
};