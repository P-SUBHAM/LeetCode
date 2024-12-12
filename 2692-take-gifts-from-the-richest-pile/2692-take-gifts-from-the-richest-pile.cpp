class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        multiset<int> st;
        for(auto it: gifts) {
            st.insert(it);
        }
        long long ans = 0;
        for(int i = 0; i < k; i++) {
            int x = *st.rbegin();
            // erases only one occurence of x from set
            st.erase(st.find(x));
            x = sqrt(x);
            st.insert(x);
        }
        for(auto it: st) {
            ans += it;
        }
        return ans;
    }
};