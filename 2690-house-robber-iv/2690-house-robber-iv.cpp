// 16Mar2025
// Approach 1: Binary Search on Answer
// for check function its always wiser to select a satisfying element than skip and try the next one as it wont be extra beneficial(greedily) 8: 7 8 4 5; 9: 7 10 3 4 
class Solution {
public:
    bool check(vector<int> &nums, int k, int x) {
        int picks = 0;
        for(auto it = nums.begin(); it < nums.end(); it++) {
            if(*it <= x) {
                picks++; it++;
            }
        }
        return picks >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(),nums.end()),
        high = *max_element(nums.begin(),nums.end()),
        ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(nums,k,mid)) {
                cout<<mid<<endl;
                ans = min(ans,mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};