class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[1][0] == edges[0][0] or edges[1][0] == edges[0][1]) {
            return edges[1][0];
        }
        else {
            return edges[1][1];
        }
        return 0;
    }
};