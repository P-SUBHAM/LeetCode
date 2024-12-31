/*
The Boyer-Moore Majority Vote algorithm works because of a fundamental property:
If an element is truly a majority element (i.e., it occurs more than `n/2` times), it will be elected by the 
algorithm at least twice, ensuring that no other element can surpass its count.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, maj = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == maj) {
                cnt++;
            }
            else if(cnt == 1) {
                maj = nums[i];
            }
            else {
                cnt--;
            }
        }
        return maj;
    }
};