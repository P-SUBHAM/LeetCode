class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size(); 
        for(int i = 0; i < n-1; i++) {
            if(nums[i]==nums[i+1]) {
                nums[i] *= 2; nums[i+1] = 0;
            }
        }
        int p1 = 0, p2 = 0;
        while(p2 < n) { // shift all zeroes to the end in O(n)
            if(nums[p2]!=0) {
                swap(nums[p2],nums[p1]); p1++;
            }
            p2++;
        }
        return nums;
    }
};