// Approach 2.2 : Patience Sort in cpp O(nlogn)
// Keep adding numbers to left most pile with higher value face up card
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<int> v(1,nums[0]);
       for(int j = 1; j < nums.size(); j++) { //O(n)
            auto it = lower_bound(v.begin(),v.end(),nums[j]); //O(logn)
            if(it == v.end()) {
                v.push_back(nums[j]);
            }
            else {
                *it = nums[j];
            }
       }
       return v.size();
    }
};

// Approach 2 : Patience Sort in cpp O(n^2)
// Keep adding numbers to left most pile with higher value face up card
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<vector<int>> v(1,vector<int>(1,nums[0]));
       for(int j = 1; j < nums.size(); j++) {
            bool put = false;
            for(int i = 0; i < v.size(); i++) {
                if(v[i].back() >= nums[j]) {
                    v[i].push_back(nums[j]);
                    put = true;
                    break;
                }
            }
            if(put == false) {
                vector<int> v1 = {nums[j]};
                v.push_back(v1);
            }
       }
       return v.size();
    }
};

// Approach 1 : Memoization O(n^2)
class Solution1 {
public:
    vector<int> dp;
    int dpf(vector<int>& nums, int i) { // LIS at i incl nums[i]
        int ans = 1;
        if(dp[i] != -1) {return dp[i];}
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                ans = max(ans,1+dpf(nums,j));
            }
        }
        return dp[i] = ans;
    } 
    int lengthOfLIS(vector<int>& nums) {
        dp.clear();
        dp.resize(nums.size(),-1);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans = max(ans,dpf(nums,i));
        }
        return ans;
    }
};
