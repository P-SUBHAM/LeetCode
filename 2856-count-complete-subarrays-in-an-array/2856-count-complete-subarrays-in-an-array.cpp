// Approach 1: Brute force
// generate all subarrays and check count of distinct subarrays
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> tot;
        for(auto it: nums) tot.insert(it);
        int ans = 0, d = tot.size(), n = nums.size();
        for(int i = 0; i < n; i++) {
            set<int> st;
            for(int j = i; j < n; j++) {
                st.insert(nums[j]);
                if(st.size() == d) ans++;
                if(st.size() > d) break;
            }
        }
        return ans;
    }
};