// Approach 1: Sorting
// sort the dominoes and compare the consecutive same dominoes using nC2
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        auto comp = [&](vector<int> &v1, vector<int> &v2) {
            if(v1[0] > v1[1]) swap(v1[0],v1[1]);
            if(v2[0] > v2[1]) swap(v2[0],v2[1]);
            if(v1[0] != v2[0]) {
                return v1[0] < v2[0];
            }
            return v1[1] < v2[1];
        };
        sort(dominoes.begin(),dominoes.end(),comp);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int I = i, cnt = 1;
            while(i+1 < n) {
                if(dominoes[i+1] == dominoes[i]) {
                    cnt++; i++;
                }
                else {
                    break;
                }
            }
            ans += cnt*(cnt-1)/2;
        }
        return ans;
    }
};