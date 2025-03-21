// Approach 1:
// first and last occurence of 1 can be used for ends,
// then for in between u can use (r-l)/2
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0, n = seats.size();
        int l = 0, r = n-1; 
        while(l < n && seats[l]!=1) {l++;}
        // while(r >= 0 && seats[r]!=1) {r--;}
        // ans = max(l,n-1-r);
        ans = l;
        r = l+1;
        while(r < n) {
            if(seats[r]!=1) {r++; continue;}
            ans = max(ans,(r-l)/2);
            l = r; r++;
        }
        ans = max(ans,n-1-l);
        return ans;
    }
};