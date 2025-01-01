// Approach 1 : Modify kadane's Algo
// keep two ptr maxpro, minpro ending at prev ind
// In multiplication, the best product at the k-th element is either the k-th element itself, the max product till (k-1) multiplied by it, or the min product till (k-1) (if negative) multiplied by it, as negative values can flip signs.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro = nums[0], minpro = nums[0], best = nums[0], n = nums.size();
        for(int i = 1; i < n; i++) {
            int M = maxpro, m = minpro;
            maxpro = max(nums[i],max(M*nums[i],m*nums[i]));
            minpro = min(nums[i],min(M*nums[i],m*nums[i]));
            best = max(best,max(minpro,maxpro));
        }
        return best;
    }
};