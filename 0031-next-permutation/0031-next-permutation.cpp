class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        // finding breakpoint -> 2 1 4 3 0 0
        // 1 is breakpoint as after that all in descending (starting from right)
        // so before 1 prefix will stay same, only permute will be required from [j,j+1,n-1]
        // we can swap j with next a[k] just > a[j](can start k from [n-1,j+1] as already descending), then reverse [j+1,n-1], so after breakpt the right half is in ascending order, only the swapped ele as it is
        int j = n-2;
        for(; j >= 0; j--) {
            if(nums[j] < nums[j+1]) break;
        }
        cout<<j;
        // entire nums in descending
        if(j == -1) {
            sort(nums.begin(),nums.end());
        }
        else {
            for(int k = n-1; k > j; k--) {
                if(nums[k] > nums[j]) {
                    swap(nums[j],nums[k]); break;
                }
            }
            reverse(nums.begin()+j+1,nums.end());
        }
    }
};