#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree;
    vector<long long> lazy;
    SegmentTree(int n_) {
        n = n_;
        tree.resize(4*n);
        lazy.resize(4*n);
    }
    void lazyUpdate(int node, int st, int en) {
        if(lazy[node] == 0) return;
        tree[node] += (en-st+1)*lazy[node];
        if(st != en) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    void rangeUpdate(int node, int st, int en, int l, int r, int diff) {
        lazyUpdate(node,st,en);
        if(st > r || en < l) return;
        if(l<=st && en<=r) {
            tree[node] += (en-st+1)*diff;
            if(st != en) {
                lazy[2*node] += diff;
                lazy[2*node+1] += diff;
            } return;
        }
        int mid = (st+en)/2;
        rangeUpdate(2*node,st,mid,l,r,diff);
        rangeUpdate(2*node+1,mid+1,en,l,r,diff);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    long long query(int node, int st, int en, int l, int r) {
        lazyUpdate(node,st,en);
        if(en < l || st > r) return 0;
        if(l <= st && en <= r) return tree[node];
        int mid = (st+en)/2;
        long long q1 = query(2*node,st,mid,l,r), q2 = query(2*node+1,mid+1,en,l,r);
        return q1+q2;
    }
    // void pointUpdate(int node, int st, int en, int ind, int val) {
    //     lazyUpdate(node,st,en);
    //     if(st == en && st == ind) {tree[node] = val; return;}
    //     int mid = (st+en)/2;
    //     if(ind <= mid) pointUpdate(2*node,st,mid,ind,val);
    //     else pointUpdate(2*node+1,mid+1,en,ind,val);
    //     tree[node] = tree[2*node] + tree[2*node+1];
    // }
};

int main()
{
    int n, q; cin>>n>>q;
    SegmentTree segtree(n);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        segtree.rangeUpdate(1,0,n-1,i,i,x);
    }
    for(int i = 0; i < q; i++) {
        int t; cin>>t;
        if(t == 2) {
            int k; cin>>k;
            cout<<segtree.query(1,0,n-1,k-1,k-1)<<endl;
        }
        else {
            int a,b,u; cin>>a>>b>>u;
            segtree.rangeUpdate(1,0,n-1,a-1,b-1,u);
        }
    }
    return 0;
}
