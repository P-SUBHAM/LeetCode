// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int modk(int n, int k){
        if(n < 0) {
            n*=-1;
            n%=k;
            n*=-1;
            n+=k;
            n%=k;
            return n;
        }
        return n%k;
    }
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int preRemSum[n];
	    preRemSum[0] = modk(arr[0],k);
        for(int i = 1; i < n; i++) {
            preRemSum[i] = modk(preRemSum[i-1] + arr[i],k);
        }
    //     for(auto it: preRemSum) {
	   //     cout<<it<<" ";
	   // }cout<<endl;
	    map<int,int> remInd;
	    for(int i = n-1; i >= 0; i--) {
	        remInd[preRemSum[i]] = i;
	    }
	    remInd[0] = -1;
	   // for(auto it: remInd) {
	   //     cout<<endl<<it.first<<" "<<it.second;
	   // }
	    int ans = 0;
	    for(int i = n-1; i >= 0; i--) {
            if(remInd.find(preRemSum[i]) != remInd.end()) {
                ans = max(ans, i - remInd[preRemSum[i]]);
            }
        }
        return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends