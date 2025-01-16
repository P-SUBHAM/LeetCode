// Approach 1: XOR logic
// xor(a1,n2)^xor(a2,n2)...^xor(an1,n2)^xor(b1,n1)^..(bn2,n1)
// xor(A,n2)^xor(B,n1)
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int A = 0, B = 0, n1 = nums1.size(), n2 = nums2.size();
        for(int i = 0; i < n1; i++) {
            A ^= nums1[i];
        }
        for(int i = 0; i < n2; i++) {
            B ^= nums2[i];
        }
        // cout<<A<<" "<<B<<endl;
        // return (A ^ (((n2%2) == 0)? A : 0)) ^ (B ^ (((n1%2) == 0)? B : 0));
        return A^(n2%2==0 ? A:0)^B^(n1%2==0 ? B:0);
    }
};