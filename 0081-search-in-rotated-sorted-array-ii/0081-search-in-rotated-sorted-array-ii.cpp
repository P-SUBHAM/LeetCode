// Approach 1: Iterative Binary Search with Duplicates // 13Mar2025
// when we get l == mid == r issue is we cant determine which half is sorted so trim down the space i.e l++, r-- (linear)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l+r)/2; cout<<l<<" "<<mid<<" "<<r<<endl;
            if(nums[mid] == target) return true;
            if(nums[l] == nums[mid] && nums[mid] == nums[r]) { // handle Duplciate entry by trimming linear search space
                l++; r--; continue;
            }
            if(nums[mid] <= nums[r]) { // right half sorted
                if(nums[mid] <= target && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else { // left half sorted
                if(nums[l] <= target && target <= nums[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};