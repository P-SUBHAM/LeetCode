class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<long long> prefix(n), suffix(n);
        prefix[0] = nums[0], suffix[n-1] = nums[n-1];
        for(int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }
        for(int j = n-2; j >= 0; j--) {
            suffix[j] = nums[j] + suffix[j+1];
        }
        for(int i = 0; i < n-1; i++) {
            if(prefix[i] >= suffix[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};