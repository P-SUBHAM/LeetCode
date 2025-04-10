// Approach 1: Digit dp
// use tight to find app limit, if s.size() is bigger than nums, return 0
class Solution {
public:
    long long dp[16][2]; // 10^15 has 16 digits
    long long digitDPf(string &nums, int idx, bool tight, string &s, int &limit) {
        cout<<"i:"<<idx<<" "<<nums<<"\n";
        if(idx > nums.size()) return 0; // to handle case when nums < s
        if(nums.size()-idx == s.size()) { // end base case
            if(!tight) return 1;
            return nums.substr(idx,s.size()) >= s;
        }
        if(dp[idx][tight] != -1) return dp[idx][tight];
        int lim = (tight)?min(limit,nums[idx]-'0'):limit;
        long long ans = 0;
        for(int i = 0; i <= lim; i++) {
            ans += digitDPf(nums,idx+1,tight&(i==nums[idx]-'0'),s,limit);
        }
        return dp[idx][tight] = ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string strFin = to_string(finish);
        string strSt = to_string(start-1);
        
        memset(dp,-1,sizeof(dp));
        long long ub = digitDPf(strFin,0,1,s,limit);
        memset(dp,-1,sizeof(dp)); // refresh dp table before each call
        long long lb = digitDPf(strSt,0,1,s,limit);
        // cout<<ub<<" "<<lb<<endl;
        return ub - lb;
    }
};