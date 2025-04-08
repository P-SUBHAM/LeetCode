// Approach 1: Use simulation to find the answer
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        unordered_set<int> st;
        for(auto it: nums) {
            if(++freq[it] == 2) {
                st.insert(it);
            }
        }
        int i = 0;
        while(!st.empty()) {
            for(int j = 0; j < 3 && i < n; i++, j++) {
                if(--freq[nums[i]] == 1) {
                    st.erase(nums[i]);
                }
            }
        }
        return ceil(1.0*i/3);
    }
};