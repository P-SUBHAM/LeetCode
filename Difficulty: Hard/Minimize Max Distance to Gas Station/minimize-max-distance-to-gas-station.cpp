//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool check(vector<int>&arr,int k, double x) {
        int n = arr.size(); int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            double u = arr[i], v = arr[i+1];
            if(v - u > x) {
                ans += floor((v-u)/x);
            }
        }
        return ans <= k;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        double low = 0, high = stations[n-1], ans = high;
        while(low < high && round(low*100)!=round(high*100)) {
            double mid = (low+high)/2;
            if(check(stations,k,mid)) {
                ans = (round(mid*100)/100);
                high = mid;
            }
            else {
                low = mid;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends