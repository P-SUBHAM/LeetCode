#include<bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            if(dq.empty()) {
                dq.push_back(nums[i]);
            }
            else  {
                while(!dq.empty() && dq.back() < nums[i]) {
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
        }
        int i = k;
        int n = nums.size();
        ans.push_back(dq.front());
        while(i < n) {
            
            
            int rem = nums[i-k];
            int add = nums[i];
            if(!dq.empty() && dq.front() == rem) {
                dq.pop_front();
            }
            while(!dq.empty() && dq.back() < nums[i]) {
                    dq.pop_back();
                }
                dq.push_back(add);
            ans.push_back(dq.front());
            i++;
        }
        return ans;
    }
};