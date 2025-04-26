// Approach 1: 2 pointer + sliding window with min and max
// check valid range btw minK & maxK
// use 2 ptr to count for each l how many subarrays can be valid 
class Solution {
public:
    long long func(vector<int>& nums, int minK, int maxK, int low, int high) {
        if(low > high) return 0;
        int l = low, r = low;
        long long ans = 0;
        deque<int> mindq;
        deque<int> maxdq;
        while(r <= high) {
            int x = nums[r]; r++;
            while(!mindq.empty() && mindq.front() > x) mindq.pop_front();
            mindq.push_front(x);
            while(!maxdq.empty() && maxdq.front() < x) maxdq.pop_front();
            maxdq.push_front(x);
            while(!mindq.empty() && mindq.back() == minK && !maxdq.empty() && maxdq.back() == maxK) {
                ans += 1ll*(high - (r-1) + 1);
                int d = nums[l]; l++;
                if(mindq.back() == d) mindq.pop_back();
                if(maxdq.back() == d) maxdq.pop_back();
            }
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int low = -1;
        long long ans = 0;
        long long x;
        for(int i = 0; i < n; i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                // cout<<low+1<<" "<<i-1<<" = ";
                x = func(nums,minK,maxK,low+1,i-1); cout<<x<<endl;
                ans += x;
                low = i;
            }
        }
        x = func(nums,minK,maxK,low+1,n-1); // cout<<low+1<<" "<<n-1<<" = "<<x<<endl;
        ans += x; 
        // cout<<ans<<endl;
        return ans;
    }
};