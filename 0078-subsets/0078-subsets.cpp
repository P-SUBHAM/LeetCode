// Approach 2: backtracking
class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>&nums, int i, vector<int> &s) {
        if(i == nums.size()) {
            ans.push_back(s); return;
        }

        rec(nums,i+1,s); // dont select

        s.push_back(nums[i]); // first select and add
        rec(nums,i+1,s);
        s.pop_back(); // backtrack after soln
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear(); vector<int> v;
        rec(nums,0,v);
        return ans;
    }
};

// Approach 1: bit manipulation
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        for(int i = 0; i < (1<<n); i++) {
            cout<<i<<" ";
            vector<int> temp;
            for(int k = 0; k < n; k++) {
                if((i & (1<<k)) != 0) {
                    temp.push_back(nums[k]);
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};