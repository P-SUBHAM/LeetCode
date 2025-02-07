// Approach 1:
// check min and max and no of ele if max==no of ele,min==1 means all ele from 1-max are present which makes it prefix-alligned upto max bits
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int minv = 1e8, maxv = 0, ans = 0, n = flips.size();
        for(int i = 0; i < n; i++) {
            minv = min(minv,flips[i]);
            maxv = max(maxv,flips[i]);
            if(minv == 1 && maxv == i+1) {
                ans++;
            }
        }
        return ans;
    }
};