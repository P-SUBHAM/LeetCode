// Approach 1: Fix two starting number + HashMap to check how many fib occureneces in arr
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), ans = 0, maxv = arr[n-1]; 
        unordered_set<int> st;
        for(auto it: arr) st.insert(it);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int a = arr[i], b = arr[j], c = a + b, cnt = 2; bool fib = true;
                while(c <= maxv) {
                    if(st.find(c)!=st.end()) {
                        a = b, b = c; cnt++; c = a+b; ans = max(ans,cnt); //correct updation here before entering while loop
                    }
                    else {
                        fib = false; break;
                    }
                }
            }
        }
        return ans;
    }
};