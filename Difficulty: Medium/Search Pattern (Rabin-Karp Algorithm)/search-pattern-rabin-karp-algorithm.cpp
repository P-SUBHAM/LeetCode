//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    // RabinKarp Algorithm using rolling hash
    public:
        int modexp(int b, int x, int p) {
            if(x == 0) return 1;
            if(x == 1) return b;
            long long ans = modexp(b,x/2,p);
            ans = (ans*ans)%p;
            if(x%2==1) {
                return (ans*b)%p;
            }
            else {
                return ans;
            }
            return 0;
        }
        vector <int> search(string pattern, string text)
        {
            int b = 31, p = 1e9+7;
            long long b1 = 1; 
            long long hash2 = 0;
            vector<int> pos;
            int n1 = text.size(), n2 = pattern.size();
            for(int i = 0; i < n2; i++) {
                hash2 += (pattern[i]*b1)%p; hash2 %= p;
                b1 *= b; b1 %= p;
            }
            long long hash1 = 0; b1 = 1;
            for(int i = 0; i < n2; i++) {
                hash1 += (text[i]*b1)%p; hash1 %= p;
                b1 *= b; b1 %= p;
            }
            b1 *= modexp(b,p-2,p); b1 %= p;
            if(hash1 == hash2) {
                // check if substr or not
                if(text.substr(0,n2) == pattern) {
                    pos.push_back(1);
                }
            }
            for(int i = n2; i < n1; i++) {
                hash1 -= text[i-n2]; hash1 = (hash1+p)%p;
                hash1 *= modexp(b,p-2,p)%p; hash1 = (hash1)%p;
                hash1 += text[i]*b1; hash1 = (hash1)%p;
                // cout<<hash1<<" "<<hash2<<endl;
                if(hash1 == hash2) {
                    if(text.substr(i-(n2-1),n2) == pattern) {
                        pos.push_back(i-(n2-1)+1);
                    }
                }
            }
            return pos;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends