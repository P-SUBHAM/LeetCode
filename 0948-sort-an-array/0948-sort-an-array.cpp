
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }

    // Approach 3: HeapSort O(nlogn)
    vector<int> HeapSort(vector<int>& nums) {
        // logic
        return nums;
    }

    // Approach 2: QuickSort O(nlogn -> n^2)
    vector<int> QuickSort(vector<int>& nums) {
        auto partition = [&](int l, int h) -> int {
            int pivot = nums[h], i = l-1; // i is ind till which val is < pivot
            for(int j = l; j < h; j++) {
                // to swap i+1 with j and then i++(incl new small into i);
                if(nums[j] < pivot) {swap(nums[i+1],nums[j]); i++;} 
            }
            swap(nums[i+1],nums[h]);
            return i+1;
        };
        function<void(int,int)> QSort = [&](int l, int h) {
            if(l < h) {
                int pi = partition(l,h);
                QSort(l,pi-1);
                QSort(pi+1,h);
            }
        };

        QSort(0,nums.size()-1);
        return nums;
    };
    // Approach 1: Bubble Sort O(n^2)
    vector<int> BubbleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[j] < nums[i]) {swap(nums[i],nums[j]);}
            }
        }
        return nums;
    }
};
