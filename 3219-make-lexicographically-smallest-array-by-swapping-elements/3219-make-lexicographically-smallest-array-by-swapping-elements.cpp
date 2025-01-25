// Approach 1: logic sorting
// sort by val,ind , check neighbours forming grp
// the neighbours are in proper order so use. grp for new grp of indexes after modif
// the earlier were in ascending order of indexsed, so pos acc to index
class Solution {
public:
    struct Compare {
        bool operator()(int a, int b) {
            return a <= b;
        }
        bool operator()(pair<int,int> a, pair<int,int> b) {
            return a.first <= b.first;
        }
    };
    void f(vector<int> &nums, vector<int> &grp) {
        vector<int> oldgrp = grp;
        sort(oldgrp.begin(),oldgrp.end());
        unordered_map<int,int> mp;
        for(auto x: grp) {
            mp[x] = nums[x];
        }
        for(int i = 0; i < grp.size(); i++) {
            nums[oldgrp[i]] = mp[grp[i]];
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> arr;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end(),Compare());
        vector<int> grp; grp.push_back(arr[0].second);
        for(int i = 1; i < n; i++) {
            if(arr[i].first-arr[i-1].first<=limit) {
                grp.push_back(arr[i].second);
            }
            else {
                // cout<<endl; for(auto x:grp) cout<<" "<<x;
                f(nums,grp); 
                grp.clear(); grp.push_back(arr[i].second);
            }
        }
        // cout<<endl; for(auto x:grp) cout<<" "<<x;
        f(nums,grp);
        return nums;
    }
};