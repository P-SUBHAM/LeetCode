class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for(int j = 1; j <= n/2; j++) {
            ans.push_back(j);
            ans.push_back(-1*j);
        }
        if(n%2==1) {
            ans.push_back(0);
        }
        return ans;
    }
};