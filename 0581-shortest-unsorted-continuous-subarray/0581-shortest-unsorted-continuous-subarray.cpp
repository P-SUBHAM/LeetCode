// Approach 2: 2ptr O(n)
// select sorted left and right part
// now iterate in middle and check if anything can expand l to left or r to right i.e if we get smaller than arr[l] or larger than arr[r]
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;
        while(l+1 < n && nums[l]<=nums[l+1]) l++;
        while(r-1 >= 0 && nums[r]>=nums[r-1]) r--;
        if(l >= r) return 0;// already sorted
        int L = l, R = r;
        for(int i = L; i <= R; i++) {
            if(l > 0 && nums[i] < nums[l-1]) {
                l--;i--;
            }
            if(r < n-1 && nums[i] > nums[r+1]) {
                r++;i--;
            }
        }
        return r-l+1;
    }
};
// Approach 1: sorting+2ptr
// sort the array and compare from left and right how many ele didn't needed sorting
class Solution1 {
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