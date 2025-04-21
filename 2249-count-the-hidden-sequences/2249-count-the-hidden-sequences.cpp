class Solution {
public:
    // Approach 1: find relative low and max possible x-low x+high, and find possibilities
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long low = 0, high = 0, n = differences.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += differences[i];
            low = min(low,sum);
            high = max(high,sum);
        }
        if(upper-lower < high-low) return 0;
        return ((upper-lower) - (high-low) + 1);
    }
};