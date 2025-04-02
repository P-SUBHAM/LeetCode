class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if(n == 0 || n == 1) {
            return s;
        }
        
        string rev_s = s;
        reverse(rev_s.begin(),rev_s.end());
        //cout<<" "<<rev_s<<" ";
        string sr = s + " " + rev_s;
        int arr[2*n+1]; arr[0] = 0;
        int i = 1, j = 0;
        while(i < 2*n+1) {
            if(sr[i] == sr[j]) {
                arr[i] = j+1;
                i++; j++;
            }
            else {
                if(j != 0) {
                    j = arr[j-1];
                }
                else {
                    arr[i] = 0;
                    i++;
                }
                
            }
        }
        
        
        int lcs = arr[2*n+1-1];
        
        string ans = "";
        
        for(int k = 0; k < n-lcs; k++) {
            ans += rev_s[k];
        }
        ans += s;
        cout<<sr<<"\n";
        for(int i = 0; i < 2*n+1; i++) {
            cout<<arr[i];
        }
        cout<<"\n";
        cout<<lcs<<"\n";
        return ans;
    }
};