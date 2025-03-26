class Solution {
public:
    int msb(int x) {
        int left0 = __builtin_clz(x);
        return 32 - left0;
    }
    int small(int b) {
        int ans = 1;
        while(--b) {
            ans <<= 1;
        }
        return ans;
    }
    int large(int b) {
        int ans = 1;
        while(--b) {
            ans <<= 1;
            ans += 1;
        }
        return ans;
    }
    long long querySolve(int l, int r) { 
        int msbl = msb(l);
        int msbr = msb(r);
        // cout<<msbl<<" "<<msbr<<endl; // dbg
        long long cnt = 0;
        for(int i = msbl+1; i <= msbr-1; i++) {
            int low = small(i);
            int high = large(i);
            int range = high - low + 1;
            cnt += range * (ceil(1.0*i/2));
        }
        // cout<<"cnt:"<<cnt<<endl; // dbg
        if(msbl == msbr) {
            // cout<<"h1 "; // dbg
            int range = r - l + 1;
            cnt += range * (ceil(1.0*msbl/2));
        }
        else {
            // cout<<"h2 "; // dbg
            int lrange = large(msbl) - l + 1;
            int rrange = r - small(msbr) + 1;
            // cout<<"rng: "<<lrange<<" "<<rrange<<endl; // dbg
            cnt += lrange * (ceil(1.0*msbl/2));
            cnt += rrange * (ceil(1.0*msbr/2));
        }
        return (cnt+1)/2;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto que: queries) {
            int l = que[0], r = que[1];
            long long currCnt = querySolve(l,r);
            // cout<<l<<" "<<r<<":"<<currCnt<<endl; // dbg
            ans += currCnt;
        }
        return ans;
    }
};