class Solution {
public:
    // check how many have number xor as 0
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int,int> mp; mp[0]++;
        int cumxor = 0;
        for(int i = 0; i < nums.size(); i++) {
            cumxor ^= nums[i];
            ans += mp[cumxor]++;
            // mp[cumxor]++;
        }
        return ans;
    }
};

class Solution1 {
public:
    // Approach 1: Bit manip
    // check how many ranges are there such that all index bits is even or xor0
    void addBits(int x, vector<int> &bits) {
        for(int i = 0; i <= 30; i++) {
            if((x&(1<<i)) > 0) bits[i] ^= 1;
        }
    }
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        vector<int> bits(30,0);
        map<vector<int>,int> bitmp; bitmp[bits]++;
        for(int i = 0; i < nums.size(); i++) {
            addBits(nums[i],bits);
            ans += bitmp[bits];
            bitmp[bits]++;
        }
        return ans;
    }
};