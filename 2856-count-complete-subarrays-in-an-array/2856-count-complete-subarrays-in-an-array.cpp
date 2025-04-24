// Approach : 2 ptr
// keep adding ele till we get distinc elements equal to whole array, add it to ans
// as distinct count can never exceed as we are comparing to whole of array
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        // unordered_set<int> tot(nums.begin(),nums.end());
        int d = unordered_set<int> (nums.begin(),nums.end()).size();
        int n = nums.size(), ans = 0;
        int l = 0, r = 0;
        unordered_map<int,int> mp;
        while(r < n) {
            mp[nums[r]]++; r++;
            while(mp.size() == d) {
                ans += n - r + 1; // 1 1 2 3 >3 3
                if(--mp[nums[l++]] == 0) {
                    mp.erase(nums[l-1]);
                }
            }
        }
        return ans;
    }
};

// Approach 1: Brute force
// generate all subarrays and check count of distinct subarrays
class Solution1 {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> tot;
        for(auto it: nums) tot.insert(it);
        int ans = 0, d = tot.size(), n = nums.size();
        for(int i = 0; i < n; i++) {
            unordered_set<int> st;
            for(int j = i; j < n; j++) {
                st.insert(nums[j]);
                if(st.size() == d) ans++;
                if(st.size() > d) break; // this situtaion will not arise as d is max pos for whole array
            }
        }
        return ans;
    }
};