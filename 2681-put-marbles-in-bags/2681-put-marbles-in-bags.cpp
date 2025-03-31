// Approach 1: Greedy
// find weight contribution pos by all partition, choose k greatest and k smallest and find diff
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        long long ans = 0;
        priority_queue<int> maxpq;
        priority_queue<int,vector<int>,greater<>> minpq;
        for(int i = 0; i < n-1; i++) {
            int combinedWeight = weights[i]+weights[i+1];
            maxpq.push(combinedWeight);
            minpq.push(combinedWeight);
        }
        while(--k) {
            int M = maxpq.top(); maxpq.pop();
            int m = minpq.top(); minpq.pop();
            ans += (M - m);
        }
        return ans;
    }
};