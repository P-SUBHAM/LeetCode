// Approach 1: Brute force
// generate all subarrays and check count of distinct subarrays
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> tot;
        for(auto it: nums) tot.insert(it);
        int ans = 0, d = tot.size(), n = nums.size();
        for(int i = 0; i < n; i++) {
            unordered_set<int> st;
            for(int j = i; j < n; j++) {
                st.insert(nums[j]);
                if(st.size() == d) ans++;
                if(st.size() > d) break; // this situtaion will not arise as d is max pos for whole array
            }
        }
        return ans;
    }
};