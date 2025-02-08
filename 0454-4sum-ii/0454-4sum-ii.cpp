// Approach 2: O(n^2)
// two loops to calc pos sums for 1&2;3&4 O(n^2)
// iterate in map12 and check for -ve in map34 O(n^2 elemenets)*O(1)check
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp12;
        unordered_map<int,int> mp34;
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++)
            for(int j = 0; j < nums2.size(); j++)
                mp12[nums1[i] + nums2[j]]++;
        for(int i = 0; i < nums3.size(); i++) {
            for(int j = 0; j < nums4.size(); j++) {
                int x = nums3[i] + nums4[j]; mp34[x]++;
                ans += mp12[-1*x]; // checking here only directly
            }
        }
        return ans;
    }
};

// Approach 1: O(n^3) TLE
// 3 loops+4th one map
class Solution1 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp4;
        for(auto x: nums4) {
            mp4[x]++;
        }
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                for(int k = 0; k < nums3.size(); k++) {
                    int x = nums1[i]+nums2[j]+nums3[k];
                    x *= -1;
                    ans += mp4[x];
                }
            }
        }
        return ans;
    }
};