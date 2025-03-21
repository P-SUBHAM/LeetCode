// Approach 1: Binary Search on Answer
class Solution {
public:
    bool check(vector<int>& ranks, int cars, long long mins) {
        long long ans = 0;
        for(int i = 0; i < ranks.size(); i++) {
            ans += sqrt(mins/ranks[i]);
            if(ans >= cars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1, high = 1LL * cars * cars * ranks[0];
        long long ans = high;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(check(ranks,cars,mid)) {
                cout<<mid<<endl;
                ans = min(ans, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};