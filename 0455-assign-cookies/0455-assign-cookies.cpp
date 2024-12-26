class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ng = g.size();
        int ns = s.size();
        int ans = 0;
        // iterate through children and make them have the next best cookie
        int i = 0, j = 0;
        while(i < ng and j < ns) {
            if(g[i] <= s[j]) {
                ans++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};