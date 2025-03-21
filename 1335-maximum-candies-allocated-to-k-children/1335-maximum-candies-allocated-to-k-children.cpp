// _14_Mar_2025_Fri
// Approach 1: Binary Search on answer
// check function checks for given x, if we can feed more than k person with x amt
class Solution {
public:
    bool check(vector<int>& candies, int x, long long k) {
        long long per = 0;
        for(auto it: candies) {
            per += it/x;
        }
        return per >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(candies,mid,k)) {
                ans = max(ans,mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};