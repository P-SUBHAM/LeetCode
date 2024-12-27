class Solution {
public:
    // Approach 2
    // Induction i-1 to i
    // for i-1 which spot gave max contri at i-1, its value for i -> maxv-1(moved 1 index to right) or find i-1's contri at i
    // max contri at i = either i-1's contri or (max contri at i-1 by someone else)'s contri at i {local contri vs global's contri}
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxvalid = values[0];
        int ans = values[1] + values[0] - 1;
        for(int i = 1; i < n; i++) {
            maxvalid = max(maxvalid - 1, values[i-1] - 1);
            ans = max(ans, values[i] + maxvalid);
        }
        return ans;
    }
};