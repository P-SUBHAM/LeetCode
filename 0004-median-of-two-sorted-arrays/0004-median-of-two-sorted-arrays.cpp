class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to minimize binary search range
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1 + n2;
        int half = total / 2;
        
        int l = 0, r = n1;
        
        while (true) {
            int i = (l + r) / 2;         // Partition index for nums1
            int j = half - i;            // Partition index for nums2
            
            // Boundaries for partitions
            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == n1) ? INT_MAX : nums1[i];
            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n2) ? INT_MAX : nums2[j];
            
            // Check if correct partition found
            if (left1 <= right2 && left2 <= right1) {
                // If total number of elements is odd
                if (total % 2 == 1) {
                    return (double) min(right1, right2);
                } else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            } else if (left1 > right2) {
                r = i - 1;  // Move partition left
            } else {
                l = i + 1;  // Move partition right
            }
        }
        return 0;
    }
};