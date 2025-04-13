// Approach 1: Binary Exponentiation recursion
class Solution {
public:
    long long mod = 1e9+7;
    long long pow(long long b, long long p) {
        if(p == 0) return 1;
        if(p == 1) return b%mod;
        long long x = pow(b,p/2);
        x = x * x; x%=mod;
        if(p%2==1) x = (x * b)%mod;
        return x%mod;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = (n+1)/2;
        return (pow(4,odd) * pow(5,even)) % mod;
    }
};