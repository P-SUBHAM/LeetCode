struct BinaryLifting {
    vector<vector<int>> up;
    int lev;
    void dfsBinaryLifting(int node, int par, vector<vector<int>> &tree) { // tree is directed graph
        up[node][0] = par;
        for (int i = 1; i <= lev && up[node][i-1]!=-1; i++)
            up[node][i] = up[up[node][i-1]][i-1]; // 2^l = 2^l-1 + 2^l-1 (2^l-1 * 2)
        for (auto child : tree[node])
            dfsBinaryLifting(child, node, tree);
    }
    void preProcess(vector<vector<int>> tree, int n) {
        lev = log2(n)+1;
        up.resize(n+1,vector<int>(lev+1,-1));
        dfsBinaryLifting(1,-1,tree);
    }
    int findKParent(int node, int k) { // k is jumps required the set bit represent lev incr
        if(k == 0 || node == -1) return node;
        for(int i = lev; i >= 0; i--) {
            if((k>>i)&1) {
                return findKParent(up[node][i],k-(1<<i));
            }
        }
    }
};
