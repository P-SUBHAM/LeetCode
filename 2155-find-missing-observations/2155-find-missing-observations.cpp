class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totSum = mean*(n + m);
        int mSum = accumulate(rolls.begin(),rolls.end(),0);
        int nSum = totSum - mSum;
        vector<int> ans;
        if(1*n > nSum or 6*n < nSum) {
            return ans;
        }
        int avg1 = nSum/n;
        int n2 = nSum - (avg1 * n);
        int n1 = n - n2;
        while(n1--) {
            ans.push_back(avg1);
        }
        while(n2--) {
            ans.push_back(avg1+1);
        }
        return ans;
    }
};