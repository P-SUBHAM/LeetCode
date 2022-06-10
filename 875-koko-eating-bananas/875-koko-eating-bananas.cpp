class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m1 = 0;
        for(int i=0;i<n;i++){
            m1 = max(m1,piles[i]);
        }
        int lo = 1;
        int high = m1;
        int ans = m1;
        if(n==h){
            return high;
        }
        while(lo<=high){
            int count = 0;
            int mid = lo + (high - lo)/2;
            for(int i = 0; i<n; i++){
                count = count + ceil(piles[i]*1.0/mid);
            }
            if(count <= h){
                ans = min(ans,mid);
                high = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};