// Approach 1: Calculate min op for each ind by tracking cumulative left and right moves use cnt += (0/1) then dist += cnt(cummulatibe distance)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int lcnt = 0, lsum = 0, rcnt = 0, rsum = 0, n = boxes.size();
        vector<int> ans(n);
        for(int j = n-1; j >= 0; j--) {
            rsum += rcnt;
            rcnt += (boxes[j] == '1');
        }
        ans[0] = rsum;
        for(int i = 0; i < n; i++) {
            ans[i] = lsum + rsum;
            lcnt += (boxes[i] == '1');
            rcnt -= (boxes[i] == '1');
            lsum += lcnt;
            rsum -= rcnt;
        }
        return ans;
    }
};