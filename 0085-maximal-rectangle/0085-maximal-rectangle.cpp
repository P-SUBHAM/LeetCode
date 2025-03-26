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
    int getLargestHistogram(vector<int> arr, int n) {
        // for(auto it: arr) cout<<it<<" "; cout<<endl;
        arr.push_back(0); n++;
        int ans = 0;
        stack<int> st; // 1 2 3 4 0 // 4 3 2 1
        // monotonic increasing stack
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                int prev = st.top(); st.pop(); //. ind = 2 h = 3
                int h = arr[prev]; // 3
                int l;
                if(st.empty()) {
                    l = i;
                }
                else { // 3 - 0 - 1
                    l = i - st.top() - 1; // i-1 - (j+1) + 1 // 1 3 2
                }
                ans = max(ans,l*h);
            }
            st.push(i);
        } // 1 2 2 0
        // cout<<ans<<endl;
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n,0);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    prev[j] += 1;
                }
                else {
                    prev[j] = 0;
                }
            }
            ans = max(ans,getLargestHistogram(prev,n));
        }
        return ans;
    }
};