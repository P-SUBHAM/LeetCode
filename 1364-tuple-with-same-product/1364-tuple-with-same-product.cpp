// Approach 1: Brute
// count freq of prod of two elements
// fC2 = f*(f-1)/2;
// (ab=cd)(ab=dc)(ba=cd)(ba=dc)<-swap(ab<->cd) => 8 comb for a pair of two product
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> mp; int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                mp[nums[i]*nums[j]]++;
            }
        }
        for(auto it: mp) {
            int f = it.second;
            // cout<<it.first<<":"<<it.second<<endl;
            ans += 8*f*(f-1)/2;
        }
        return ans;
    }
};