class Solutionp {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; // decrease mono stack
        unordered_map<int,int> mp;
        for(int i = 0; i < nums2.size(); i++) {
            if(st.empty()) {
                st.push(i); continue;
            }
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                int cur = st.top(); st.pop();
                mp[nums2[cur]] = nums2[i];
            }
            st.push(i);
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

// Approach 1: Using monotonic decreasing stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> mono_dec_st;
        for(int i = 0; i < nums2.size(); i++) {
            while(!mono_dec_st.empty() && nums2[i] > nums2[mono_dec_st.top()]) {
                int cur = mono_dec_st.top(); mono_dec_st.pop();
                mp[nums2[cur]] = nums2[i];
            }
            mono_dec_st.push(i);
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