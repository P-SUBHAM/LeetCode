//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        auto xorfunc = [&](int a, int b) {
            return a^b;
        };
        int x_y = accumulate(arr.begin(),arr.end(),0,xorfunc);
        int bit = (x_y&-x_y);
        int bitind = __builtin_ctz(bit);
        int set1 = 0, set2 = 0;
        for(auto it: arr) {
            if((it&(1<<bitind)) > 0) {
                set1 ^= it;
            }
            else {
                set2 ^= it;
            }
        }
        // cout<<bitind<<endl;
        return {min(set1,set2),max(set1,set2)};
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends