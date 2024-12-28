// Approach 1 using prefix postfix array
class Solution {
public:
    // sum = [left] + [mid] + [right]
    // keep iterating mid subarray, and check max sum from left and right possible
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // For All pos index with subarray sum
        // max sum of subarray from left
        vector<int> left;
        // subarray sum from ith index
        vector<int> mid;
        // max sum of subarray from right
        vector<int> right;
        // left updation
        int karraysum = accumulate(nums.begin(),nums.begin()+k,0);
        mid.push_back(karraysum);
        for(int i = k; i < n; i++) {
            karraysum += (nums[i] - nums[i-k]);
            mid.push_back(karraysum);
        }
        int N = mid.size();
        int maxv = mid[0];
        left.push_back(0);
        for(int i = 1; i < N; i++) {
            if(mid[i] > maxv) {
                maxv = mid[i];
                left.push_back(i);
            }
            else {
                left.push_back(left.back());
            }
        }
        maxv = mid[N-1];
        right.resize(N);
        right[N-1] = N-1;
        for(int j = N-2; j >= 0; j--) {
            if(mid[j] >= maxv) {
                maxv = mid[j];
                right[j] = j;
            }
            else {
                right[j] = right[j+1];
            }
        }
        vector<int> ans;
        maxv = 0;
        for(int i = k; i < N - k; i++) {
            // mid contains subarray sum
            // left contains max leftmost subbaray sums's starting index
            // i.e mid = sum left = index
            int locmax = mid[left[i-k]] + mid[i] + mid[right[i+k]];
            // storing index into ans
            if(locmax > maxv) {
                ans = {left[i-k],i,right[i+k]};
                maxv = locmax;
            }
        }
        return ans;
    }
};