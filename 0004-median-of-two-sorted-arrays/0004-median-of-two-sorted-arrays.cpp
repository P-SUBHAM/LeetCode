class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), half = (n1 + n2)/2;
        if(n1 > n2) return findMedianSortedArrays(nums2,nums1);
        for(auto it: nums1) cout<<it<<" "; cout<<endl;
        for(auto it: nums2) cout<<it<<" "; cout<<endl;

        int low = 0, high = n1;
        while(low <= high) {
            int i = (low+high)/2; // line partition 0->| 1 |<-1 2 3 4 |<- n
            int j = half - i;
            cout<<low<<high<<" ";
            cout<<i<<j<<endl;
            int l1 = (i == 0)?INT_MIN:nums1[i-1];
            int r1 = (i == n1)?INT_MAX:nums1[i];
            int l2 = (j == 0)?INT_MIN:nums2[j-1];
            int r2 = (j == n2)?INT_MAX:nums2[j];
            if(l1 <= r2 && l2 <= r1) {
                if((n1+n2)%2==0) {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else {
                    return min(r1,r2);
                }
            }
            else if(l1 > r2) {
                high = i - 1;
            }
            else if(l2 > r1) {
                low = i + 1;
            }

            // n1+n2 4 5 odd 4,4 5 5 (n1+n2-1)/2 (n1+n2)/2
            //     even 4 6 4,4 5 5
            
        }
        return 0;
    }
};

// Approach 1: using Binary search to equate n1=n2 on both side
// consider l1,r1,l2,r2 are values on left and right of partition, partition is not index but a line
// // line partition 0->| 1 |<-1 2 3 4 |<- n
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to minimize binary search range
        if (nums1.size() > nums2.size()) { // imp as in othr case if n1 is greater it may lead to mid1 = 0 and mid2 going out og bound in nums2(as smaller size)
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