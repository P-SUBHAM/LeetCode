// Approach 1: QuickSelect
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    auto partition = [&](int l, int h) -> int {
      int pivot = nums[h], i = l-1;
      for(int j = l; j < h; j++) {
        if(nums[j] < pivot) {
          swap(nums[i+1],nums[j]);
          i++;
        }
      }
      swap(nums[i+1],nums[h]);
      return i+1;
    }; 
    function<int(int, int, int)> QuickSelect = [&](int l, int h,int k) -> int {
      int pi = partition(l, h);
      if (pi == k) {
        return nums[k];
      } else if (pi < k) {
        return QuickSelect(pi+1, h, k);
      } else {
        return QuickSelect(l, pi - 1, k);
      }
    };
    return QuickSelect(0,nums.size()-1,nums.size()-k);
  }
};