// Approach:1 
// n^2 for every nums[i] check which nums[j] will increase the len by max, and nums[j] is factor of nums[i] and all till nums[j] are factors mutually 
class Solution {
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