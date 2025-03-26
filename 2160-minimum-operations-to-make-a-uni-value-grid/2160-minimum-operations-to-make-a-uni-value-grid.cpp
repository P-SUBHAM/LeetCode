class Solution {
public:
    bool isModuloMatch(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = grid[0][0] % x;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int currMod = grid[i][j] % x;
                if(currMod != mod) return false;
            }
        }
        return true;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        bool canModuloMatch = isModuloMatch(grid,x);
        if(!canModuloMatch) return -1;
        int noOfOperations = INT_MAX;
        vector<int> v;
        int totalSum = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int ele = grid[i][j];
                totalSum += ele;
                v.push_back(ele);
            }
        }
        sort(v.begin(),v.end());
        int sumTillPrev = 0;
        int vLen = v.size();
        for(int i = 0; i < vLen; i++) {
            int currEle = v[i];

            int lenTillEnd = vLen - i;
            int lenTillBegin = i;

            int currSumTillEnd = totalSum - sumTillPrev;
            int finalSumTillEnd = lenTillEnd * currEle;

            int currSumTillBegin = sumTillPrev;
            int finalSumTillBegin = lenTillBegin * currEle;

            sumTillPrev += currEle;

            int reqOperations = (currSumTillEnd - finalSumTillEnd)/x + (finalSumTillBegin - currSumTillBegin)/x;
            noOfOperations = min(noOfOperations,reqOperations);
        }
        return noOfOperations;
    }
};