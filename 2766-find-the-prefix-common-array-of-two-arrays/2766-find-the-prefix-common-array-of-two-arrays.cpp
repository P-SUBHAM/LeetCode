// Approach 1:
// logic: add previously occured ele from both array into hashmap
// for curr index if these ele already exist add 1 extra count to cnt val till now
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(); vector<bool> mp(n,false);
        vector<int> ans;
        ans.push_back(A[0] == B[0]);
        mp[A[0]] = true, mp[B[0]] = true;
        for(int i = 1; i < n; i++) {
            if(A[i] == B[i]) {
                mp[A[i]] = true;
                ans.push_back(ans[i-1] + 1);
            }
            else {
                int x = (mp[A[i]] + mp[B[i]]);
                ans.push_back(ans[i-1] + x);
                mp[A[i]] = true, mp[B[i]] = true;
            }
        } 
        return ans;
    }
};