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
        else { // cnt == 0 replace maj ele
            maj = it; 
            cnt = 1;
        }
    }
    cnt = 0;
    for(auto it: nums) {
        if(it == maj) cnt++;
    }
    if(cnt > n/2) { // check abs maj
        return maj;
    }
    return -1;
}