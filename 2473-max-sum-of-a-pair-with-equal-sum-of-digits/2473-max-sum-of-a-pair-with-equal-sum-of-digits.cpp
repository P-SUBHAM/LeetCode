// Approach 1: Map digitSum:list<digit>
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,multiset<int>> mp;
        int n = nums.size();
        function<int(int)> digitsum = [&](int x)->int {
            int sum = 0;
            while(x > 0) {
                sum += x%10; x/=10;
            } return sum;
        };
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = digitsum(x);
            mp[sum].insert(x);
            if(mp[sum].size()==3) {
                mp[sum].erase(mp[sum].begin());
            }
        }
        int ans = -1;
        for(auto pair: mp) {
            auto st = pair.second;
            cout<<pair.first<<":";
            for(auto it: pair.second) cout<<it<<" "; cout<<endl;
            if(st.size()<=1) continue;
            auto it = st.rbegin(); 
            int sum = *it; it++;
            sum += *it;
            ans = max(ans,sum);
        }
        return ans;
    }
};

/*
3: 3 12 21 111
4: 4 13 22 112 121 
5: 5 14 23 114
*/