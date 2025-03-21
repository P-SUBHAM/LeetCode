//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool check(vector<int> &arr, int k, int maxpg) {
        int cnt = 1, sum = 0;
        for(auto it: arr) {
            if(sum + it <= maxpg) {
                sum += it;
            }
            else {
                sum = it;
                cnt++;
            }
        }
        return cnt <= k;
    }
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;
        int low = *max_element(arr.begin(),arr.end()), 
        high = accumulate(arr.begin(),arr.end(),0),
        ans = 1e8;
        while(low <= high) {
            int mid = (low+high)/2;
            if(check(arr,k,mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return (ans==1e8)?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends