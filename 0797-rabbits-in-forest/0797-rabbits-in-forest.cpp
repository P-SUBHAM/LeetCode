// Approach 1: Puzzle/logic
// if a rabbit says x then all rabbits of same colour will also say x, and total rabbits = (1+x)
// sort arr, whenever a new rabbit says x, add x+1 to ans, and skip max current x+1 rabbits 
class Solution {
public:
    // puzzle
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        sort(answers.begin(),answers.end());
        int i = 1, maxv = answers[0], cnt = 1, ans = maxv+1;
        while(i < n) {
            // cout<<"i: "<<i<<" maxv: "<<maxv<<" cnt: "<<cnt<<endl;
            if(answers[i] == answers[i-1] && cnt+1 <= maxv+1) {
                i++; cnt++; // cnt is how many who answered i can group together to skip
            }
            else {
                maxv = answers[i]; i++;
                ans += maxv+1; cnt = 1;
            }
        }
        return ans;
    }
    // [0,0,1,1,1]
};