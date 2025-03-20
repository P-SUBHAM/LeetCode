// Approach 1: Backtracking
class Solution {
public:
    void rec(vector<int> &arr, int i, int tar, vector<int> &v, vector<vector<int>> &ans) {
        if(i == arr.size()) { // base condition(final cond)
            if(tar == 0) {
                ans.push_back(v);
            }
            return;
        }
        // pick or not pick
        if(arr[i] <= tar) { // then i can pick
            v.push_back(arr[i]);
            rec(arr,i,tar-arr[i],v,ans);
            v.pop_back();
        }
        rec(arr,i+1,tar,v,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        rec(candidates,0,target,v,ans);
        return ans;
    }
};