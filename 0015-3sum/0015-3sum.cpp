class Solution {
public:
    // 2 pointer approach with sorting
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n;) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    while(l < n && nums[l] == nums[l-1]) {
                        l++;
                    }
                    r--;
                    while(r >= 0 && nums[r] == nums[r+1]) {
                        r--;
                    }
                }
                else if(sum > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
            i++;
            while(i < n && nums[i] == nums[i-1]) {
                i++;
            }
        }
        return ans;
    }
    // Using Hashing (311/313)
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int n = nums.size();
    //     set<vector<int>> soln;
    //     for(int i = 0; i < n; i++) {
    //         unordered_set<int> exists;
    //         for(int j = i + 1; j < n; j++) {
    //             int k = -1 * (nums[i] + nums[j]);
    //             if(exists.find(k) != exists.end()) {
    //                 vector<int> toinsert = {nums[i],nums[j],k};
    //                 sort(toinsert.begin(),toinsert.end());
    //                 soln.insert(toinsert);
    //             }
    //             exists.insert(nums[j]);
    //         }
    //     }
    //     vector<vector<int>> ans(soln.begin(),soln.end());
    //     return ans;
    // }
};