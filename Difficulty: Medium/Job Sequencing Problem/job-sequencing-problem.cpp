//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    struct job {
        int end;
        int profit;
        int id;
        
        job(int end_, int profit_, int id_) : end(end_),profit(profit_),id(id_) {}
    };
    struct comp {
        bool operator()(const job &j1, const job &j2) const {
            if(j1.profit > j2.profit) return true;
            else if(j1.profit < j2.profit) return false;
            else j1.end > j2.end;
        }  
    };
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<job> v;
        set<int> st; 
        int ans = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            v.push_back(job(deadline[i],profit[i],i+1));
            st.insert(i+1);
        }
        sort(v.begin(),v.end(),comp());
        for(int i = 0; i < n; i++) {
            auto indit = st.lower_bound(v[i].end);
            // cout<<v[i].end<<"-";
            if(indit != st.end() && *indit == v[i].end) {
                // cout<<*indit<<" ";
                ans+=v[i].profit; st.erase(indit); cnt++;
            }
            else {
                if(indit != st.begin()) {
                    indit--;
                    if(*indit < v[i].end) {
                        st.erase(indit);
                        ans+=v[i].profit; cnt++;
                    }
                }
            }
            // cout<<endl;
        }
        return {cnt,ans};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends