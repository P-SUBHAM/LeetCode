// Approach 1: Using monotonic stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> mono_inc_st;
        for(int i = 0; i < nums2.size(); i++) {
            while(!mono_inc_st.empty() && nums2[i] > nums2[mono_inc_st.top()]) {
                int cur = mono_inc_st.top(); mono_inc_st.pop();
                mp[nums2[cur]] = nums2[i];
            }
            mono_inc_st.push(i);
        }
        vector<int> ans(nums1.size(),-1);
        for(int i = 0; i < nums1.size(); i++) {
            if(mp.find(nums1[i]) != mp.end()) {
                ans[i] = mp[nums1[i]];
            }
        }
        return ans;
    }
};