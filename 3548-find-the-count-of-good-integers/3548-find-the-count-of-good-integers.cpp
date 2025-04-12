// Approach 1: recursion
// generate k-palindromic string, then calculate permutations, subtract invalid 0 strings
class Solution {
public:
    long long fact[11] = {1};
    vector<int> num;
    unordered_set<string> numPerm;
    long long ans = 0;
    long long permuteNumMap(unordered_map<int,int> cntmp, int n) {
        long long cnt = fact[n];
        for(auto pair: cntmp) {
            int freq = pair.second;
            cnt /= fact[freq];
        }
        return cnt;
    }
    long long permute(string num, int n) {
        unordered_map<int,int> cntmp;
        for(auto ch: num) {
            cntmp[ch-'0']++;
        }
        long long cnt = permuteNumMap(cntmp,n);
        long long x = 0;
        // cout<<num<<":"<<cnt<<"-"; // debug
        if(cntmp[0] > 0) {
            cntmp[0]--;
            x = permuteNumMap(cntmp,n-1);
            cnt -= x;
        }
        // cout<<x<<"="<<cnt<<endl; // debug
        return cnt;
    }
    void generateKPalindrome(int pos,string &num, int n, int k) {
        if(pos >= (n+1)/2) {
            string s = num; sort(s.begin(),s.end());
            if(stoll(num)%k == 0 and numPerm.find(s) == numPerm.end()) {
                numPerm.insert(s);
                long long x = permute(num,n);
                ans += x;
            }
            return;
        }
        char st = (pos == 0)?'1':'0';
        for(char i = st; i <= '9'; i++) {
            num[pos] = i;
            num[n-1-pos] = i;
            generateKPalindrome(pos+1,num,n,k);
        }
    }
    long long countGoodIntegers(int n, int k) {
        for(int i = 1; i <= 10; i++) fact[i] = i * fact[i-1];
        string num = string(n,' ');
        generateKPalindrome(0,num,n,k);
        return ans;
    }
};