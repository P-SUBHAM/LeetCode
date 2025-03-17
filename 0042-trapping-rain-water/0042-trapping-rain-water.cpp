// practice 202503180111
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[i] > height[st.top()]) { // dont forget height[st.top()]
                int curr = st.top(); st.pop();
                if(st.empty()) continue;
                ans += (min(height[st.top()],height[i])-height[curr])*(i-st.top()-1);
            }
            st.push(i); 
        }
        return ans;
    }
};

// Approach 2: monotonic decreasing stack 
// to keep track of max on left, once we get curr > stack.top we know we are getting a container
// we calc water for each horizontal level (st.top-1,st.top)*hor dist
class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> st; int n = height.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(st.empty() || height[i] <= height[st.top()]) {
                st.push(i); continue;
            }
            while(!st.empty() && height[st.top()] < height[i]) {
                int cur = st.top(); st.pop();
                if(st.empty()) continue; // no left container to close
                cout<<height[st.top()]<<" "<<height[i]<<" "<<height[cur]<<endl;
                ans += (min(height[st.top()],height[i]) - height[cur]) * (i - st.top() - 1);
            }
            
            st.push(i);
        }
        return ans;
    }
};

// Aproach 1: prefix, suffix array 
class Solution1 {
public:
    vector<int> maxr;
    vector<int> maxl;
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) {
            return 0;
        }
        maxr.resize(n,-1);
        maxl.resize(n,-1);
        maxr[n-1]=height[n-1];
        for(int i = n-2; i >= 0; i--) {
            maxr[i] = max(height[i],maxr[i+1]);
        }
        maxl[0]=height[0];
        for(int i = 1; i < n; i++) {
            maxl[i] = max(height[i],maxl[i-1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (min(maxr[i],maxl[i])-height[i]);
        }
        for(int i = 0; i < n; i++) {
            cout<<maxr[i]<<" ";
        }cout<<"\n";
        for(int i = 0; i < n; i++) {
            cout<<maxl[i]<<" ";
        }cout<<"\n";
        return ans;
    }
};

/* count = 3;
18 mar 25
16 mar 25
15 apr 21
*/