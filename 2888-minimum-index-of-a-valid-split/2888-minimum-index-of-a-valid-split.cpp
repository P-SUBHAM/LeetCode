// Approach: Find majority element using Boyer-Moore Voting Algorithm
class Solution {
public:
    int getMajorityElement(vector<int>& nums, int &cnt) {
        int n = nums.size();
        cnt = 1;
        int maj = nums[0];
        for(auto it: nums) {
            if(it == maj) {
                cnt++;
            }
            else if(cnt > 0) {
                cnt--;
            }
            else {
                maj = it; 
                cnt = 1;
            }
        }
        cnt = 0;
        for(auto it: nums) {
            if(it == maj) cnt++;
        }
        if(cnt > n/2) {
            return maj;
        }
        return -1;
    }
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int totalCnt = 0;
        int majorityElement = getMajorityElement(nums, totalCnt);
        if(majorityElement == -1) return -1;
        int leftCnt = 0;
        for(int i = 0; i < n-1; i++) {
            int leftLen = i+1;
            int rightLen = n - leftLen;
            if(nums[i] == majorityElement) leftCnt++;
            int rightCnt = totalCnt - leftCnt;
            if(leftCnt > leftLen/2 && rightCnt > rightLen/2) {
                return i;
            }
        }
        return -1;
    }
};