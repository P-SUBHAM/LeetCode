// Approach 1: simulate using heap/multiset
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<int> st;
        for(auto it: nums) st.insert(it);
        int ans = 0;
        while(*st.begin() < k) {
            if(st.size() <= 2) {
                ans++; st.clear(); break;
            }
            auto it = st.begin();
            int a = *it; it++; int b = *it;
            cout<<a<<","<<b<<":";
            st.erase(st.find(a)); st.erase(st.find(b)); 
            long long x = 1LL*min(a,b)*2+max(a,b);
            cout<<x<<endl;
            if(x < 1LL*k) st.insert(x);
            ans++;
        }
        return ans;
    }
};