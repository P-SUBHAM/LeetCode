// practice
// Monotonic increasing stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), ans = 0;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            // if(st.empty() || heights[i] > heights[st.top()]) {
            //     st.push(i);
            // }
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int cur = st.top(); st.pop();
                if(st.empty()) {
                    ans = max(ans,heights[cur]*i); continue;
                }
                // cout<<heights[cur]*(i-st.top()-1)<<endl;
                ans = max(ans,heights[cur]*(i-st.top()-1));
            }
            st.push(i);
        }
        return ans;
    }
};


// Approach 1: using stack
// ith h contributes till last index just smaller than h because all ele
// bw h_i and Hi will be more 17652 5 contri till 1 next
class Solution1 {
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
                    len = i - (st.top()+1); // use this bcs some h b/w 1564->14
                    ans = max(ans,len*h);
                }
            }
            st.push(i);
            i++;
        }
        return ans;
    }
};