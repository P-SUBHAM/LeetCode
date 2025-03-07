// Approach 1: Prime Sieve
class Solution {
public:
    vector<bool> prime;
    vector<int> closestPrimes(int left, int right) {
        prime.resize(right+1,true); prime[0] = prime[1] = false;
        for(int i = 2; i <= right; i++) {
            if(prime[i]) {
                for(int j = 2*i; j <= right; j += i) {
                    prime[j] = false;
                }
            }
        }
        vector<int> ans = {-1,-1};
        int p1 = -1, p2 = -1; int i = left;
        for(; i <= right; i++) {
            if(prime[i]) {
                p1 = i; i++; break;
            }
        }
        for(; i <= right; i++) {
            if(prime[i]) {
                p2 = i; i++; break;
            }
        }
        cout<<p1<<" "<<p2<<endl;
        if(p2 == -1) return {-1,-1};
        ans = {p1,p2};
        for(; i <= right; i++) {
            if(prime[i]) {
                p1 = p2; p2 = i;
                if(p2 - p1 < ans[1] - ans[0]) {
                    ans = {p1,p2};
                }
            }
        }
        return ans;
    }
};