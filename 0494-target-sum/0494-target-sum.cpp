// APROACH 2.3 - memoization using 2d vector // normalize -target by +1e5
class Solution {
public:
    vector<vector<int>> dp;
    int dpf(vector<int>& nums, int target, int ind) {
        int n = nums.size();
        if(ind == n) {
            if(target == 0) {
                return 1;
            }
            return 0;
        }
        if(dp[2e4+target][ind] != -1) {
            return dp[2e4+target][ind];
        }
        return dp[2e4+target][ind] = dpf(nums,target-nums[ind],ind+1) + dpf(nums,target+nums[ind],ind+1);

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        dp.resize(1e5,vector<int>(nums.size()+1,-1));
        return dpf(nums, target, 0);
    }
};

/*
// APPROACH-2.2
class Solution {
public:
    // DP using memoization
    // using unordered map with hash for pair type
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ (h2 << 1); // Combine the hashes
        }
    };
    
    unordered_map<pair<int,int>,int,pair_hash> dp;
    int findTargetSumWaysf(vector<int> &nums, int target, int ind) {
        int n = nums.size();
        if(ind == n - 1) {
            if(target == nums[ind] or target == -1*nums[ind]) {
                if(nums[ind] == 0) {
                    return dp[{target,ind}] = 2;
                }
                return dp[{target,ind}] = 1;
            }
            return dp[{target,ind}] = 0;
        }
        if(dp.find({target,ind})!=dp.end()) {
            return dp[{target,ind}];
        }
        return dp[{target,ind}] = findTargetSumWaysf(nums,target-nums[ind],ind+1) + findTargetSumWaysf(nums,target+nums[ind],ind+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return findTargetSumWaysf(nums,target,0);
    }
};
*/

// FOR vector and set
// template <typename Container>
// struct container_hash {
//     template <typename T>
//     size_t operator()(const Container& c) const {
//         size_t hash_val = 0;
//         for (const auto& elem : c) {
//             hash_val ^= hash<T>{}(elem) + 0x9e3779b9 + (hash_val << 6) + (hash_val >> 2);
//         }
//         return hash_val;
//     }
// };
// unordered_map<pair<int,int>,int,container_hash<vector<int>>> dp;