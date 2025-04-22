class Solution {
public:
    // Approach 1: pnc
    // find prime factors of k, distribute prime factors into n pos, rest all 1
    // for distributing distribute each prime factor based on its freq 
    const int mod = 1e9+7;
    static const int N = 20001;
    int fact[N];
    int modpow(int b, int p) {
        b %= mod;
        if(p == 0) return 1;
        if(p == 1) return b%mod;
        long long x = modpow(b,p/2);
        x = (x*x)%mod;
        if(p%2 == 1) x = (x*b)%mod;
        return x;
    }
    int modinv(int a) { // a^p=amodp => a^-1=a^p-2modp
        return modpow(a,mod-2);
    }
    int C(int n, int k) { // nCk
        long long ans = fact[n];
        ans = (ans*modinv(fact[k]))%mod;
        ans = (ans*(modinv(fact[n-k])))%mod;
        return ans;
    }
    map<int,int> primefactor(int x) {
        map<int,int> mp;
        int pfac = 0;
        for(int i = 2; i*i <= x; i++) {
            while(x%i == 0) {
                mp[i]++;
                x/=i;
            }
        }
        if(x > 1) mp[x]++;
        return mp;
    }
    int func(int n, int k) {
        map<int,int> primefactormp = primefactor(k);
        long long ans = 1;
        for(auto pair: primefactormp) {
            int p = pair.first, x = pair.second;
            ans = (ans * C(n+x-1,n-1))%mod;
        }
        // cout<<"n:"<<n<<" k:"<<k<<" C:"<<ans<<endl;
        return ans;
    }
    void preprocessfact() {
        fact[0] = fact[1] = 1;
        for(int i = 2; i < N; i++) {
            fact[i] = (1ll*fact[i-1]*i)%mod;
        }
        // for(int i = 0; i < 10; i++) cout<<fact[i]<<" "; cout<<endl;
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> ans;
        preprocessfact();
        for(auto q: queries) {
            int n = q[0], k = q[1];
            ans.push_back(func(n,k));
        }
        return ans;
    }
};