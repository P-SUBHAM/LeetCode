class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size()-1;
        while(j <= k) {
            // for(auto it: nums) cout<<it<<" "; cout<<endl;
            // for(int x = 0; x < nums.size(); x++) {
            //     if(x == i || x == j || x == k) cout<<"^ ";
            //     else cout<<"  ";
            // }cout<<endl;
            if(nums[j] == 0) swap(nums[i++],nums[j++]);// in start j, i if no j++;
            else if(nums[j] == 2) swap(nums[j],nums[k--]);
            else if(nums[j++] == 1) {}
        }
    }
};

// Approach 1: DNF sort
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, n = nums.size(), h = n - 1;
        while(m <= h) {
            if(nums[m] == 0) {
                swap(nums[l],nums[m]); l++; m++;
            }
            else if(nums[m] == 2) {
                swap(nums[m],nums[h]); h--;
            }
            else {
                m++;
            }
        }
    }
};