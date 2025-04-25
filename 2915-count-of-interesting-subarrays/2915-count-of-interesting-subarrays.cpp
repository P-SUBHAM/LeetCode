// Approach 1: Modulo Arithmetic + count
// transform nums into 1,0 arr if satisy nums[i]%mod == k
// find no of subarray with sum%mod == k
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int> mp;
        vector<int> prefixSum = {0}; mp[0]++; // cout<<"0 "; 
        for(int i = 0; i < n; i++) {
            if(nums[i] % modulo == k) nums[i] = 1;
            else nums[i] = 0;
            int x = prefixSum.back() + nums[i]; x %= modulo;
            int y = (x-k+modulo)%modulo;// x-y+y-k%mod == k+y-k
            ans += mp[y]; 
            prefixSum.push_back(x); mp[x]++;
            // cout<<prefixSum[i+1]<<" ";
        } // cout<<endl;
        return ans;
    }
};