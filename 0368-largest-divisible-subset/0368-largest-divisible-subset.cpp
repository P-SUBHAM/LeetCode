// Approach 2: DP
// fix i, search for next element which is mul of i, 
// call dpf on next factor, store these factors index in a map to backtrack
class Solution {
public:
    unordered_map<int,int> div;
    int dpf(vector<int>& nums, int i, vector<int> &dp) {
        int n = nums.size(), ans = 1;
        if(i == n-1) return dp[i] = 1;
        if(dp[i] != -1) return dp[i];
        for(int j = i+1; j < n; j++) {
            if(nums[j]%nums[i]==0 && 1+dpf(nums,j,dp) > ans) {
                div[nums[i]] = j;
                ans = max(ans,1+dpf(nums,j,dp));
            }
        }
        return dp[i] = ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        div.clear();
        vector<int> dp(n,-1);
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++) {
            if(div.find(nums[i])==div.end()) div[nums[i]] = i;
            ans = max(ans,dpf(nums,i,dp));
        }
        int ind = max_element(dp.begin(),dp.end()) - dp.begin();
        vector<int> ansv;
        while(div[nums[ind]] != ind) {
            ansv.push_back(nums[ind]); ind = div[nums[ind]];
        } ansv.push_back(nums[ind]);
        // for(auto it: dp) cout<<it<<" "; cout<<endl;
        // for(auto it: nums) cout<<div[it]<<" "; cout<<endl;
        return ansv;
    }
};

// Approach:1 
// n^2 for every nums[i] check which nums[j] will increase the len by max, and nums[j] is factor of nums[i] and all till nums[j] are factors mutually 
class Solution1 {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> div;
        int n = nums.size();
        vector<int> cnt(n);
        int maxf = 1, ele = nums[0];
        for(int i = 0; i < n; i++) {
            cnt[i] = 1;
            div[nums[i]] = nums[i];
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && cnt[j]+1 >= cnt[i]) {
                    cnt[i] = cnt[j]+1;
                    div[nums[i]] = nums[j];
                    if(cnt[i] > maxf) {
                        maxf = cnt[i]; ele = nums[i];
                    }
                }
            }
            // for(auto it: div) {
            //     cout<<it.first<<"->"<<it.second<<" ";
            // } cout<<endl;
        }
        vector<int> ans;
        ans.push_back(ele);
        // for(auto it: nums) cout<<it<<" "; cout<<endl;
        // for(auto it: cnt) cout<<it<<" ";
        while(div[ele] != ele) {
            ele = div[ele];
            ans.push_back(ele);
        }
        return ans;
    }
};