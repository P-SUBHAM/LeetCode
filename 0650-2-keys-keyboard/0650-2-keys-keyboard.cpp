// Approach 1: Logic Recursion/DP
// whatever is the largest divisor of n form that and copy it and paste it n/div times to get n
// if n is prime u have to paste A n times
class Solution {
public:
    unordered_map<int,int> dp;
    int minStepsdp(int n) {
        if(dp.find(n)!=dp.end()) return dp[n];
        // cout<<n<<":\n";
        if(n<=1) return 0;
        if(n==2) return 2;
        if(n==3) return 3;
        int ans = n;
        for(int i = 2; i*i<=n; i++) {
            if(n%i==0) {
                int ans1 = minSteps(i)+(n/i); // form i and copy1+paste n/i-1
                int ans2 = minSteps(n/i)+(i); // form n/i and copy1+paste i-1
                // cout<<i<<":"<<ans1<<" "<<ans2<<endl;
                ans = min({ans,ans1,ans2});
            }
        }
        // cout<<n<<"->"<<ans<<endl;
        return dp[n] = ans; // dp
        return ans; // recursion
    }
    int minSteps(int n) {
        // dp.clear(); // same val can be reused
        return minStepsdp(n);
    }
};