// Approach 1: Modified kadane algo
// ai,k = 1..50 so select ai and plan to convert to k
// choosen x->k convert x->1 and k to -1(as if it comes in subarray it'll be changed and it'll lead to red in k)
class Solution {
public:
    int kadf(vector<int>& nums, int k, int a) { // convert a to k
        function<int(int)> val = [&](int x) {
            //if a==k: a=k=1 else 0
            //if a!=k: a->1 and k->(-1) else 0
            if(a==k) return x==k?0:0;// cause we have kcnt
            return x==a?1:(x==k?-1:0);
        };
        int sum = 0, maxsum = 0, kcnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]==k) kcnt++;
            int x = val(nums[i]);
            sum = max(x,sum+x);
            maxsum = max(maxsum,sum);
        }
        return kcnt + maxsum;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 1; i <= 50; i++) {
            ans = max(ans,kadf(nums,k,i));
        }
        return ans;
    }
};