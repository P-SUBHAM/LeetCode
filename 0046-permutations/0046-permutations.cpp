// Approach 2: using STL 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        do {
            ans.push_back(nums);
        } while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};

// Approach 1: Algorithmically
class Solution1 {
public:
    vector<vector<int>> ans;
    void AllPermuteRec(vector<int> nums, int l, int r) {
        // add to ans if all elements permuted till last element
        if(l == r) {
            ans.push_back(nums); return;
        }
        // swap l th element with all elements on right[l to r] and call the recursion
        for(int j = l; j <= r; j++) {
            swap(nums[l],nums[j]);
            AllPermuteRec(nums,l+1,r);
            swap(nums[j],nums[l]);
        }
        // for(int j = l; j <= r; j++) {
        //     vector<int> newnums;
        //     newnums = nums;
        //     swap(newnums[l],newnums[j]);
        //     AllPermuteRec(newnums,l+1,r);
        // }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        ans.clear();
        AllPermuteRec(nums,0,n-1);
        return ans;
    }
};