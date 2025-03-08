// Approach 1: Sliding window
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = k, black = 0;
        int l = 0, r = 0;
        while(r < k) {
            if(blocks[r++] == 'B') {
                black++;
            }
        }
        ans = k - black; //cout<<ans<<endl;
        while(r < blocks.size()) {
            if(blocks[r++] == 'B') black++;
            if(blocks[l] == 'B') black--;
            l++;
            ans = min(ans,k-black);
            // cout<<k-black<<endl;
        }
        return ans;
    }
};