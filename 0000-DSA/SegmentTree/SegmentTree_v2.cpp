#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int n_) {
        n = n_;
        tree.resize(4*n);
    }
    void pointUpdate(int node, int st, int en, int ind, int val) {
        if(st == en && st == ind) {tree[node] = val; return;}
        int mid = (st+en)/2;
        if(ind <= mid) pointUpdate(2*node,st,mid,ind,val);
        else pointUpdate(2*node+1,mid+1,en,ind,val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    int query(int node, int st, int en, int l, int r) {
        if(en < l || st > r) return 0;
        if(l <= st && en <= r) return tree[node];
        int mid = (st+en)/2;
        int q1 = query(2*node,st,mid,l,r);
        int q2 = query(2*node+1,mid+1,en,l,r);
        tree[node] = tree[2*node] + tree[2*node+1];
        return q1+q2;
    }
};

int main()
{
    int n, q; cin>>n>>q;
    SegmentTree segtree(n);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        segtree.pointUpdate(1,0,n-1,i,x); // segtree 1 based <-(1),(0,n-1)->arr 0 based
    }
    for(int i = 0; i < q; i++) {
        int a,b,c; cin>>a>>b>>c;
        if(a == 2) {
            cout<<segtree.query(1,0,n-1,b-1,c-1)<<endl;
        }
        else {
            segtree.pointUpdate(1,0,n-1,b-1,c);
        }
    }
    return 0;
}
