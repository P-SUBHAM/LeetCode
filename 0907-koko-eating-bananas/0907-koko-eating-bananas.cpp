// 13_Mar_2025_Thu
// Approach 1: Binary Search on Answer
class Solution {
public:
    bool check(vector<int>& piles, int x, int h) {
        long time = 0;
        for(auto it: piles) {
            time += ceil(1.0*1LL*it/x);
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, n = piles.size(), r = *max_element(piles.begin(),piles.end());
        int ans = r;
        while(l <= r) {
            int mid = (l+r)/2;
            if(check(piles,mid,h)) {
                ans = min(ans,mid);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

class Solution_11_May_2022 {
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