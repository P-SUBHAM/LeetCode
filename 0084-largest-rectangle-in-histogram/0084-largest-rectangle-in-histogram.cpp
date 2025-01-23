// Approach 1: using stack
// ith h contributes till last index just smaller than h because all ele
// bw h_i and Hi will be more 17652 5 contri till 1 next
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st; int ans = 0; int i = 0, n = heights.size();
        while(i < n) {
            while(!st.empty() and heights[st.top()] > heights[i]) {
                int t = st.top(); st.pop();
                int h = heights[t];
                if(st.empty()) {
                    ans = max(ans,h*i);
                }
                else {
                    int len = i-t; // not this
                    len = i - (st.top()+1); // use this
                    ans = max(ans,len*h);
                }
            }
            st.push(i);
            i++;
        }
        return ans;
    }
};