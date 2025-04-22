#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_multiset<int> omst;
        vector<int> v(1,0); omst.insert(nums.back());
        for(int i = nums.size()-2; i >= 0; i--) {
            int x = nums[i];
            int smallCnt = omst.order_of_key(x);
            v.push_back(smallCnt);
            omst.insert(x);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};