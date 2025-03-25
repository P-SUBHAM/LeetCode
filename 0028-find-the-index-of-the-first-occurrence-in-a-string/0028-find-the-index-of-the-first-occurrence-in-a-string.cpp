// practice
class Solution {
public:
    vector<int> prefix_func(string &s) {
        int n = s.size();
        int i = 1, j = 0;
        vector<int> prefix(n,0);
        while(i < n) {
            j = prefix[i-1];
            while(j > 0 && s[i] != s[j]) {
                j = prefix[j-1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            prefix[i] = j;
            i++;
        }
        return prefix;
    }
    int strStr(string haystack, string needle) {
        vector<int> prefix = prefix_func(needle);
        cout<<"prefix:"; for(auto it: prefix) cout<<it<<" "; cout<<endl;
        int n = haystack.size(), m = needle.size();
        vector<int> occur;
        int i = 0, j = 0;
        while(i < n) {
            if(haystack[i] == needle[j]) {
                i++; j++;
            }
            else {
                if(j > 0) {
                    j = prefix[j-1];
                }
                else {
                    i++;
                }
            }
            if(j == m) {
                occur.push_back(i - m);
                j = prefix[j-1];
            }
        }
        if(occur.size() > 0) return occur[0];
        return -1;
    }
};


// Approach 3.1 Rabin Karp
class Solution3_1 {
public:
    int mod = 1e9+7;
    int p = 31;
    int calcHash(string needle) {
        int n = needle.size();
        int powp = 1;
        int hash = 0;
        for(int i = 0; i < n; i++) {
            hash += (1ll*(needle[i]-'a'+1)*powp)%mod;
            hash %= mod;
            powp = (powp * (1ll*p))%mod;
        }
        return hash;
    }
    int powr(int b, int power) {
        if (power == 0) return 1;
        int x = powr(b, power / 2);
        x = (1LL * x * x) % mod;  // Squaring the result
        if (power % 2 == 1) {
            x = (1LL * x * b) % mod;  // If odd, multiply by base b
        }
        return x;
    }
    int strStr(string haystack, string needle) {
        int needleHash = calcHash(needle);
        int powp = 1;
        int pinv = powr(p,mod-2);
        int m = needle.size();
        int n = haystack.size();
        powp = powr(p,m-1);
        cout<<powp<<":"<<pinv<<endl;
        int rollingHash = calcHash(haystack.substr(0,m));
        for(int i = 0; i < n - (m-1); i++) {
            if(needleHash == rollingHash) return i;
            cout<<needleHash<<":"<<rollingHash<<endl;
            rollingHash = (rollingHash - (haystack[i]-'a'+1) + mod)%mod;
            rollingHash = (1LL*rollingHash*pinv)%mod;
            rollingHash = (1LL*rollingHash + 1LL*(haystack[i+m]-'a'+1)*powp)%mod;
            // if (i < n - m) {
            //     // Remove the old character from the hash and add the new character
            //     rollingHash = (rollingHash - (haystack[i] - 'a' + 1) + mod) % mod;
            //     rollingHash = (1LL * rollingHash * pinv) % mod;  // Use the inverse of p
            //     rollingHash = (1LL * rollingHash + (haystack[i + m] - 'a' + 1) * powp) % mod;
            // }
        }
        return -1;
    }
};



// Approach 3: Rabin Karp string hashing
class Solution3 {
public:
    int m = 1e9+7;
    int p = 31;
    int calcHash(string needle) {
        int n = needle.size();
        int powp = 1;
        int hash = 0;
        for(int i = 0; i < n; i++) {
            hash += (1ll*(needle[i]-'a'+1)*powp)%m;
            hash %= m;
            powp = (powp * (1ll*p))%m;
        }
        return hash;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        vector<long long> parr(n+1,1);
        for(int i = 1; i <= n; i++) {
            parr[i] = (1LL*parr[i-1] * p)%m;
        }
        // for(auto it: parr) cout<<it<<" "; cout<<endl; 
        vector<long long> hayarr(n+1);
        for(int i = 0; i < n; i++) {
            hayarr[i+1] = (hayarr[i] + ((haystack[i] - 'a' + 1)*parr[i])%m)%m;
        }
        // for(auto it: hayarr) cout<<it<<" "; cout<<endl; 
        int needlehash = calcHash(needle);
        int sn = needle.size();
        // p^i*(hash i..j) (hash j - hash i-1)
        for(int i = 0; i < n - (sn-1); i++) {
            int j = i + sn - 1;
            int rollhash = (hayarr[j+1] - hayarr[i]);
            cout<<rollhash<<":"<<needlehash * parr[i]<<endl;
            if(needlehash * parr[i] == rollhash) {
                return i;
            }
        }
        return -1;
    }
};

// Approach 2: KMP 
// check the prefix logic of j = prefix[j-1]; // to not start from first but from last prefix matched
class Solution2 {
public:
    vector<int> prefixf(string s) {
        int n = s.size();
        vector<int> prefix(n,0);
        for(int i = 1; i < n; i++) {
            int j = prefix[i-1];
            while(j > 0 && s[i] != s[j]) {
                j = prefix[j-1];
            }
            if(s[i] == s[j]){
                j++;
            }
            prefix[i] = j;
        }
        return prefix;
    }
    int strStr(string haystack, string needle) {
        vector<int> prefix = prefixf(needle);
        int i = 0, j = 0;
        while(i < haystack.size()) {
            if(haystack[i] == needle[j]) {
                i++; j++;
            }
            else {
                if(j==0) {
                    i++;
                }
                else {
                    j = prefix[j-1];
                }
            }
            if(j == needle.size()) {
                return i - needle.size();
            }
        }
        return -1;
    }
};

class Solution1 {
public:
    vector<int> lps(string str) {
        int n = str.size();
        vector <int> lpsv(n,0);
        int i(1), j(0);
        while(i < n) {
            if(str[i] == str[j]) {
                lpsv[i] = j + 1;
                i++;
                j++;
            }
            else {
                if(j != 0) {
                    j = lpsv[j-1];
                }
                else {
                    lpsv[i] = 0;
                    i++;
                }
            }
        }
        return lpsv;
    }
    
    int kmp(string s, string str) {
        vector<int> lpsv = lps(str);
        // for(auto it: lpsv) {
        //     cout<<it<<" ";
        // }
        int n = s.size();
        int i(0), j(0);
        while(i < n) {
            if(s[i] == str[j]) {
                i++;
                j++;
            }
            else {
                if(j != 0) {
                    j = lpsv[j-1];
                }
                else {
                    i++;
                }
            }
            if(j == str.size()) {
                return i - j;
            }
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};