// Approach 1: Pascal triangle using Binomial Expansion
class Solution {
public:
    int Choose(int n, int r) {
        int ans = 1;
        for(int i = n; i > r; i--) {
            ans *= i;
            ans /= (n - i + 1);
        }
        return ans;
    }
    vector<vector<int>> generate(int n) {
        // (a+b)^n = nC0a^nb^0 + nc1a^n-1b1...nCna^0b^n
        vector<vector<int>> ans = {{1}};
        if(n == 0) return ans;
        for(int i = 1; i < n; i++) {
            vector<int> row;
            for(int x = 0; x <= i; x++) {
                row.push_back(Choose(i,x));
            }
            ans.push_back(row);
        }
        return ans;
    }
};