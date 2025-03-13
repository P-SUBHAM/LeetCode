
// 13_Mar_2025
// Approach 1: Modified Binary Search
// check if mid is peak, if not CHOOSE THE INCREASING HALF
// in increasing half either there is element midway which is peak or the last element is default peak
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l+r)/2;
            int midl = INT_MIN, midr = INT_MIN;
            if(mid - 1 >= 0) midl = nums[mid - 1];
            if(mid + 1 < nums.size()) midr = nums[mid + 1];
            if(midl < nums[mid] && nums[mid] > midr) return mid;
            if(nums[mid] < midr) {l = mid + 1; continue; }
            else {r = mid - 1;}
        }
        return 0;
    }
};

class Solution_13_Jul_2021 {
public:
    int fp(vector<int> &arr, int l, int r) {
        if(r-l==0) {
            return l;
        }
        else if(r-l==1) {
            if(arr[l] > arr[r]) {
                return l;
            }
            else {
                return r;
            }
        }
        int mid = (l+r)/2;
        int ln = mid-1, rn = mid+1;
        if(arr[mid] > arr[ln] && arr[mid] > arr[rn]) {
            return mid;
        }
        else if(arr[rn] > arr[mid] && arr[mid] > arr[ln]) {
            return fp(arr,mid,r);
        }
        else if(arr[ln] > arr[mid] && arr[mid] > arr[rn]) {
            return fp(arr,l,mid);
        }
        else {
            return fp(arr,l,mid);
        }
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return fp(nums,0,n-1);
    }
};