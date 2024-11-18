class Solution {
public:
    map<int,int> sum;
    int sumfunc(int n, int l, int r) {
        // cout<<"l:"<<l<<" "<<"r:"<<r<<"\n";
        if(r >= l) {
            // cout<<sum[r]<<"-"<<sum[l-1]<<"\n";
            return sum[r] - sum[l-1];     
       }
       else {
            return sum[n-1]-sum[l-1]+sum[r];
            // cout<<sum[n-1]<<"-"<<sum[l-1]<<"+"<<sum[r]<<"\n";
       }
    }
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans;
        sum.clear();
        sum[-1] = 0;
        for(int i = 0; i < n; i++) {
            sum[i] = sum[i-1] + code[i];
        }
        // for(auto it: sum) cout<<it.second<<" ";
        // cout<<"\n";
        for(int i = 0; i < n; i++) {
            if(k == 0) {
                ans.push_back(0);
            }
            else if(k > 0) {
                int l = (i+1)%n, r = (i+1+k-1)%n;
                ans.push_back(sumfunc(n,l,r));
            }
            else {
                int K = k*(-1);
                // cout<<"k:"<<k<<" ";
                int l = (i-1+n-(K-1))%n;
                int r = (i-1+n)%n;
                ans.push_back(sumfunc(n,l,r));
            }
        }
        return ans;
    }
};