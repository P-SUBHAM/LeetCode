struct SegmentTree {
    vector<int> arr; // 0 based
    vector<long long> tree; // 1 based
    vector<long long> lazy; // for lazy propagation in range updation
    int n;
    void build(int node, int st, int en) {
        if(st == en) {
            tree[node] = arr[st]; return;
        }
        int mid = (st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        tree[node] = tree[2*node] + tree[2*node+1]; // logic
    }
    void pointUpdate(int node, int st, int en, int ind, int val) {
        if(lazy[node]!=0) {
            tree[node] += (en - st + 1) * lazy[node]; 
            if(st!=en) { // extra part to update the child segment
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            else {
                arr[st] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(st == en && st == ind) {
            arr[ind] = val; tree[node] = val; return;
        }
        int mid = (st+en)/2;
        if(ind <= mid) {
            pointUpdate(2*node,st,mid,ind,val);
        }
        else {
            pointUpdate(2*node+1,mid+1,en,ind,val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    void rangeUpdate(int node, int st, int en, int l, int r, int diff) {
        if(lazy[node]!=0) {
            tree[node] += (en - st + 1) * lazy[node]; 
            if(st!=en) { // extra part to update the child segment
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            else {
                arr[st] += diff;
            }
            lazy[node] = 0;
        }
        if(st > r || en < l) return; // no overlap
        if(l <= st && en <= r) {
            tree[node] += (en - st + 1) * diff;
            if(st != en) {
                lazy[2*node] += diff;
                lazy[2*node+1] += diff;
            }
            else {
                arr[st] += diff;
            }
            return;
        }
        int mid = (st+en)/2;
        rangeUpdate(2*node,st,mid,l,r,diff);
        rangeUpdate(2*node+1,mid+1,en,l,r,diff);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    // {ST:node->st,en} {query:l,r}
    int query(int node, int st, int en, int l, int r) { // 0 based
        if(lazy[node]!=0) {
            tree[node] += (en - st + 1) * lazy[node]; 
            if(st!=en) { // extra part to update the child segment
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            else {
                arr[st] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(st > r || en < l) return 0; // no overlap
        if(l <= st && en <= r) { // segment tree node complete overlap within range query
            return tree[node];
        } 
        int mid = (st+en)/2;
        int q1 = query(2*node,st,mid,l,r), q2 = query(2*node+1,mid+1,en,l,r);
        return q1 + q2; // logic
    }
    SegmentTree(vector<int> a) {
        arr = a;
        n = a.size();
        tree.resize(4*n, 0);
        lazy.resize(4*n, 0);
        build(1,0,n-1); // node is 1 based
    }
};