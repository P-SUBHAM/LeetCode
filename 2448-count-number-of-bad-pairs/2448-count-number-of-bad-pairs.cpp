// Approach 1: FreqMap + reordering
// j-i!=nums[j]-nums[i]=>nums[i]-i!=nums[j]-j
// bad pairs = nC2 - goodPairs(nums[i]-i)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<long long, long long> mp; long long ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) ans += mp[nums[i] - i]++;
        return 1LL*n*(n-1)/2 - ans;
    }
};