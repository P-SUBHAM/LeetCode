// Approach 1: sort by first index and then keep merging intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int> v = {-1,-1}; vector<int> v2 = {-1,-1};
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(v == v2) {
                v = intervals[i];
            }
            else if(v[1] < intervals[i][0]) {
                ans.push_back(v);
                v = intervals[i];
            }
            else if(v[1] >= intervals[i][1]) {
                continue;
            }
            else {
                v[1] = intervals[i][1];
            }
        }
        if(v != v2) {
            ans.push_back(v);
        }
        return ans;
    }
};