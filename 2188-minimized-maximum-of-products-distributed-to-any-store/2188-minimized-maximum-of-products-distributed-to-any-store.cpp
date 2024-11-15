class Solution {
public:
    int helper(int n, vector<int> &quantities, int x) {
        int s = 0;
        for(int i = 0; i < quantities.size(); i++) {
            s += ceil(1.0*quantities[i]/x);
        }
        // cout<<"help:"<<x<<" s:"<<s<<"\n";
        return s <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxv = 0;
        for(int i = 0; i < quantities.size(); i++) {
            maxv = max(maxv,quantities[i]);
        }
        int low = 1, high = maxv, ans = maxv;
        while(low <= high) {
            int mid = (low + high)/2;
            // cout<<low<<" "<<mid<<" "<<high<<"\n";
            if(helper(n,quantities,mid)) {
                ans = mid;
                // cout<<ans<<"\n";
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};