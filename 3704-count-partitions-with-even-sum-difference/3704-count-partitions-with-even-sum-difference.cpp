// Approach 1: use prefix sum to check if same parity on left and right subarray
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> v = nums;
        int n = nums.size(), ans = 0;
        for(int i = 1; i < n; i++) {
            v[i] += v[i-1];
        }
        for(int i = 1; i < n; i++) {
            if(v[i]%2==(v[n-1]-v[i])%2) ans++;
        }
        return ans;
    }
};