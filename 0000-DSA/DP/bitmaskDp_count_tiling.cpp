#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

void generateNextMasks(int currmask, int nextMask, int j, int m, vector<int> &nextMasks) {
    if(j == m+1) {
        nextMasks.push_back(nextMask); return;
    }
    if((currmask&(1<<j))!=0) {//jth bit is filled
        generateNextMasks(currmask,nextMask+0,j+1,m,nextMasks);
    }
    if((currmask&(1<<j))==0) { // not filled and fill horizontal mask
        generateNextMasks(currmask+(1<<j),nextMask+(1<<j),j+1,m,nextMasks);
    }
    if(j < m && (currmask&(1<<j))==0 && (currmask&(1<<(j+1)))==0) {
        generateNextMasks(currmask+(1<<j)+(1<<(j+1)),nextMask,j+2,m,nextMasks);
    }
}

int dpf(int i, int mask, int m, int n, vector<vector<int>> &dp) {
    if(i == n+1) {
        return mask == 0;
    }
    if(dp[i][mask] != -1) return dp[i][mask];
    vector<int> nextMasks;
    generateNextMasks(mask,0,1,m,nextMasks);
    int ans = 0;
    for(auto nextMask: nextMasks) {
        ans = (1LL*ans + dpf(i+1,nextMask,m,n,dp))%mod;
    }
    return dp[i][mask] = ans;
}

void count_tilings()
{
    int m,n; cin>>m>>n;
    vector<vector<int>> dp(n+1,vector<int>(1<<(m+1),-1));
    int ans = dpf(1,0,m,n,dp);
    cout<<ans;
}

int main()
{
    count_tilings();
    return 0;
}