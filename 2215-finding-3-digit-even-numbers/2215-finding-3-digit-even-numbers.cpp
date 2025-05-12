// Approach 1: Brute
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ansSt;
        int n = digits.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    int number = 100*digits[i]+10*digits[j]+digits[k];
                    if(number >= 100 && number%2 == 0) {
                        ansSt.insert(number);
                    }
                }
            }
        }
        vector<int> ans = vector<int>(ansSt.begin(),ansSt.end()); // vector declaration from set
        return ans;
    }
};