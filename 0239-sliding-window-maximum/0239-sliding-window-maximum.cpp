// Approach 1.1: Using Deque
// if a larger element comes all smaller elements currently in deque are of no use
// if a smaller element comes then it should be considered as it can contirbute as max in the future
// while removing the element check if it is current max(then remove) 
// the higher no on right of smaller can only occur if smaller(newer) came after higher(older) so when removing higher(older) is removed then the newer becomes older it also gets removed
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // incr: 1 2 3 4
        vector<int> ans;
        int i = 0;
        for(; i < k; i++) {
            while(!dq.empty() && nums[i] > dq.front()) {
                dq.pop_front();
            }
            dq.push_front(nums[i]);
        }
        ans.push_back(dq.back());
        for(; i < nums.size(); i++) {
            if(nums[i - k] == dq.back()) {
                dq.pop_back();
            }
            while(!dq.empty() && nums[i] > dq.front()) {
                dq.pop_front();
            }
            dq.push_front(nums[i]);
            ans.push_back(dq.back());
        }
        return ans;
    }
};

#include<bits/stdc++.h>
class Solution1 {
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