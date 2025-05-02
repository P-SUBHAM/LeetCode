// Approach 1: Greedy
// for each index find nearest R on left ot L on right, if same dist then .
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), inf = n;
        vector<int> left(n,inf), right(n,inf);
        switch(dominoes[0]) {
            case 'R': left[0] = 0; break;
            case 'L':
            case '.': break;
        }
        for(int i = 1; i < n; i++) {
            if(dominoes[i] == 'L') {
                // default inf case
            }
            else if(dominoes[i] == 'R') {
                left[i] = 0;
            }
            else {
                left[i] = min(inf,left[i-1] + 1);
            }
        }
        if(dominoes[n-1] == 'L') {
            right[n-1] = 0;
        }
        for(int i = n-2; i >= 0; i--) {
            if(dominoes[i] == 'L') {
                right[i] = 0;
            }
            else if(dominoes[i] == 'R') {
                right[i] = inf; // default inf case
            }
            else {
                right[i] = min(inf,right[i+1] + 1);
            }
        }
        // for(auto it: left) cout<<it<<" "; cout<<endl;
        // for(auto it: right) cout<<it<<" "; cout<<endl;
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(left[i] == right[i]) {
                ans += ".";
            }
            else if(left[i] < right[i]) {
                ans += "R";
            }
            else {
                ans += "L";
            }
        }
        return ans;
    }
};