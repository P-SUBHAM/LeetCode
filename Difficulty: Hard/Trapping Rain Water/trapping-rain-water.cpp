//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n,arr[0]);
        vector<int> right(n,arr[n-1]);
        for(int i = 1; i < n; i++) {
            left[i] = max(left[i-1],arr[i]);
        }
        for(int j = n-2; j >= 0; j--) {
            right[j] = max(right[j+1],arr[j]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += max(0,min(left[i],right[i]) - arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends