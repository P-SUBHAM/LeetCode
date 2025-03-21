// Approach 1: Bit Manipulation
// because any two no should have & as 0, so the bit val can be set only once by each no
// if you keep taking xor, the set bits will keep accumlating i.e contrib of all nos r++
// so if any no is unsetting an already set bit then it cant be included in arr so l++
class Solution {
public:
    bool checkbit(int x, int y) {
        for(int i = 0; i < 31; i++) {
            int bit1 = (x>>i)&1;
            int bit2 = (y>>i)&1;
            if(bit1==bit2 && bit1 == 1) return false;
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int xorv = 0, l = 0, r = 0, n = nums.size(), ans = 0;
        while(r < n) {
            if(!checkbit(xorv,nums[r])) {
                xorv^=nums[l]; l++;
            }
            else {
                xorv^=nums[r]; r++;
            }
            // cout<<l<<":"<<r<<endl;
            ans = max(ans,r-l);
        }
        return ans;
    }
};