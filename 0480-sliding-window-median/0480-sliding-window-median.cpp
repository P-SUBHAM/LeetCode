// Approach 1: using 2 sets to store left and right half
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if(k==1) {
            vector<double> v; for(auto it: nums) v.push_back(it); return v;
        }
        multiset<int> low, high;
        vector<double> ans; int n = nums.size();
        for(int i = 0; i < k; i++) {
            int x = nums[i];
            if(low.size() <= high.size()) { // lower heavy
                low.insert(x);
            }
            else {
                high.insert(x);
            }
            if(high.empty()) continue;
            if(*low.rbegin() > *high.begin()) {
                int a = *low.rbegin(); low.erase(low.find(a));
                int b = *high.begin(); high.erase(high.find(b));
                low.insert(b); high.insert(a);
            }
        }
        if(k%2==0) {
            ans.push_back(1.0*(*low.rbegin()*1LL+*high.begin())/2);
        }
        else {
            ans.push_back(*low.rbegin());
        }
        for(int i = k; i < n; i++) {
            int r = nums[i-k], a = nums[i];
            if(r <= *low.rbegin()) {
                low.erase(low.find(r)); 
                if(low.size()<high.size()) {
                    int p = *high.begin(); high.erase(high.find(p)); low.insert(p);
                }
            }
            else {
                high.erase(high.find(r));
                if(low.size()>high.size()+1) {
                    int p = *low.rbegin(); low.erase(low.find(p)); high.insert(p);
                }
            }
            if(a <= *low.rbegin()) {
                low.insert(a); // check if bal needed
                if(low.size()>high.size()+1) {
                    int p = *low.rbegin(); low.erase(low.find(p)); high.insert(p);
                }
            }
            else {
                high.insert(a);
                if(low.size()<high.size()) {
                    int p = *high.begin(); high.erase(high.find(p)); low.insert(p);
                }
            }
            if(k%2==0) {
                ans.push_back(1.0*(*low.rbegin()*1LL+*high.begin())/2);
            }
            else {
                ans.push_back(*low.rbegin());
            }
        }
        return ans;
    }
};