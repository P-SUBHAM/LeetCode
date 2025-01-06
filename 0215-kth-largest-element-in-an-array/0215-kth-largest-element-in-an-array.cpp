// Approach 1: QuickSelect
// Approach 2: MaxHeap
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    return findKthLargestMaxHeap(nums,k);
  }
  // Approach 2: Using MaxHeap O(N+klogN)
  int findKthLargestMaxHeap(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<int> pq;
    for(auto x: nums) {
        pq.push(x);
    }
    while(k-- > 1) {
        pq.pop();
    }
    return pq.top();
  }
  // Approach 1: QuickSelect O(n -> n^2)
  int QuickSelect(vector<int>& nums, int k) {
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
    function<int(int, int, int)> QSelect = [&](int l, int h,int k) -> int {
      int pi = partition(l, h);
      if (pi == k) {
        return nums[k];
      } else if (pi < k) {
        return QSelect(pi+1, h, k);
      } else {
        return QSelect(l, pi - 1, k);
      }
    };
    return QSelect(0,nums.size()-1,nums.size()-k);
  }
};