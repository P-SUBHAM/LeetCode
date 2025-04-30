// Approach 1: Brute force using Accumulate
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        function<int(int a, int b)> func = [&](int a, int b)->int { // a is accumulate 0, b is arr item
            int d = 0;
            while(b > 0) {
                d++; b/=10;
            }
            return a + (d%2 == 0);
        } ;
        return accumulate(nums.begin(),nums.end(),0,func);
    }
};