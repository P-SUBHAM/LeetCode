// Approach 1: Logic n should be square of prime no
// 1 n sqrt(n) are only 3 factors, check upto sqrt(n)
class Solution {
public:
    bool isThree(int n) {
        int cnt=0;
        for(int i = 2; i*i <= n; i++) {
            if(n%i==0) cnt += (i*i==n?1:2);
        }
        // cout<<cnt;
        return cnt==1;
    }
};