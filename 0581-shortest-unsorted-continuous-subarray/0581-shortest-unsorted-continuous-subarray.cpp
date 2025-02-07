// Approach 1: sorting+2ptr
// sort the array and compare from left and right how many ele didn't needed sorting
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(),arr.end()); // nonDecreasing=>Ascending
        int l = 0, n = arr.size(), r = n-1;
        while(l < n && nums[l]==arr[l]) l++;
        while(r >= 0 && nums[r]==arr[r]) r--;
        return max(0,n - l - (n-1-r)); // l-r=r-l+1
    }
};