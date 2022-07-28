class Solution {
public:
    map<int,int> leader;
    map<int,int> size;
    int n;
    void makel(int x) {
        leader[x] = x;
        size[x]++;
    }
    int findl(int x) {
        if(leader[x] == x) {
            return x;
        }
        return leader[x] = findl(leader[x]);
    }
    void unionl(int x, int y) {
        int a = findl(x);
        int b = findl(y);
        if(size[a] < size[b]) {
            leader[a] = b;
            size[b] += size[a];
        }
        else {
            leader[b] = a;
            size[a] += b;
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected[0].size();
        for(int i = 0; i < n; i++) {
            makel(i);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    unionl(i,j);
                }
            }
        }
        set<int> ans;
        for(int i = 0; i < n; i++) {
            ans.insert(findl(i));
        }
        return ans.size();
    }
};