// Approach 1: 
// use prefix sum to find out how many pairs exist that can given odd subarray sum.
// odd = (odd-even)+(even-odd)
class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int even = 1, odd = 0, sum = 0, n = arr.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum%2==0) { // we got even so we check how many odd till now to pair up
                ans += odd;
                even++;
            }
            else {// we got odd sum so check how many even pair to gice odd subarray sum
                ans += even;
                odd++;
            }
            ans %= M;
        }
        return ans;
    }
};