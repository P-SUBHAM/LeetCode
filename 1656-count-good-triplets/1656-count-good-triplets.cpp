// Approach 1: Brute
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    int A = arr[i], B = arr[j], C= arr[k];
                    if(abs(A-B) <= a && abs(B-C) <= b && abs(A-C) <= c) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};