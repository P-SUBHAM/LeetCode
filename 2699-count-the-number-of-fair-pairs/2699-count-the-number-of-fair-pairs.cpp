// Approach 1: Using multiset
// keep adding nums[j] and before adding check range of nums[i] and add to ans
// lower - nums[j] <= nums[i] <= upper - nums[j];

// policy based data structure ordered_set
// template named 'tree'
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
// __gnu_pbds::null_type

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();

        // normal multiset TLE
        // multiset<int> st; st.insert(nums[0]);
        // for(int j = 1; j < n; j++) {
        //     // lower - nums[j] <= nums[i] <= upper - nums[j];
        //     auto itr = st.upper_bound(upper-nums[j]);
        //     auto itl = st.lower_bound(lower-nums[j]);
        //     ans += 1LL*(distance(itl,itr));
        //     st.insert(nums[j]);
        // }

        // ordered_multiset based on policy based data structure
        ordered_multiset<int> omst; omst.insert(nums[0]);
        for(int j = 1; j < n; j++) {
            // lower - nums[j] <= nums[i] <= upper - nums[j];
            auto itr = omst.order_of_key(upper-nums[j]+1); // it finds strictly lesser
            auto itl = omst.order_of_key(lower-nums[j]);
            int ele = *omst.find_by_order(0);
            ans += 1LL*(itr-itl);
            omst.insert(nums[j]);
        }

        return ans;
    }
};