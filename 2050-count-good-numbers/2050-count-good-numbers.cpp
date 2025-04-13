// Approach 1: Binary Exponentiation recursion
class Solution {
public:
    long long mod = 1e9+7;
    long long powR(long long b, long long p) {
        b %= mod;
        if(p == 0) return 1;
        if(p == 1) return b;
        long long x = pow(b,p/2);
        x = (x * x) % mod;
        if(p%2==1) x = (x * b) % mod;
        return x;
    }
    // b^p = b^p0*b^p1*b^p2...
    long long powI(long long b, long long p) {
        b %= mod;
        long long ans = 1;
        while(p > 0) {
            if(p & 1) ans = (ans * b) % mod;
            b = (b * b) % mod;
            p >>= 1;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n+1)/2;
        return (powI(4,odd) * powI(5,even)) % mod;
    }
};