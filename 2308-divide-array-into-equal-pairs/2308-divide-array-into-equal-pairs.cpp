// Approach 1: 
// each element should have even prequency to be divided into multiple of pairs
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums) mp[it]++;
        for(auto it: mp) 
            if(it.second%2==1) return false;
        return true;
    }
};