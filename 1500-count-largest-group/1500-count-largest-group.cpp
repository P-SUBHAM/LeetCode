class Solution {
public:
    // Approach 1: Maps
    // keep 1 map to check size of digitSum grp
    // use 2nd map to check size of diigtSum, and update accordingly
    int countLargestGroup(int n) {
        unordered_map<int,int> grpSize; int maxlen = 0;
        unordered_map<int,int> grpSizeFreq;

        function<int(int)> getDigitSum = [&](int x) {
            int sum = 0;
            while(x > 0) {
                sum += x%10; x/= 10;
            }
            return sum;
        };

        for(int i = 1; i <= n; i++) {
            int digitSum = getDigitSum(i);

            ++grpSize[digitSum];
            grpSizeFreq[grpSize[digitSum]]++;
            // grpSizeFreq[grpSize[digitSum]-1]--; // not req for qsn req

            maxlen = max(maxlen,grpSize[digitSum]);
        }
        return grpSizeFreq[maxlen];
    }
};