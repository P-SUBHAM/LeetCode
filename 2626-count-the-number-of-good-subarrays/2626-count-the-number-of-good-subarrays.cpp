// Approach 1: 2 ptr + counting
// as long as countgood is < k keep adding r, once it satsifies count no of good array formed using n-r+1 for each l, and as long as its satisfies keep doing l++
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        long long count = 0;
        long long ans = 0;
        unordered_map<int,int> mp;
        while(r < n || count >= k) {
            if(count < k) {
                count += mp[nums[r++]]++;
            }
            else {
                count -= --mp[nums[l++]];
            }
            
            if(count >= k) {
                ans += (n-r+1);
                // cout<<(n-r+1)<<" ";
            }
            // cout<<count<<endl;
        }
        return ans;
    }
};