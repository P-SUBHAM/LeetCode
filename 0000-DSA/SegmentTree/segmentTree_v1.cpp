#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> tree;

// Node -> corresponds to index in tree(4*N) st,en range suggested by node in arr(N)
//           [1,4]N1      [st,en]nodeNo
//          /       \
//     [1,2]N2     [3,4]N3
//     /   \        /     \
// [1,1]N4[2,2]N5 [3,3]N6[4,4]N7

// node is tree node index in tree[]; st,en are index in range(0,n-1) corresponding to node index
void build(int node, int st, int en) {
    if(st == en) {
        tree[node] = arr[st]; 
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid); // build left half
    build(2*node+1,mid+1,en); // build right half
    tree[node] = tree[2*node] + tree[2*node+1]; // update node from child value Main Logic
}

// [st,en] is arr range range for treeNode i.e part of segment tree to consider, [l,r]->range for a
int query(int node, int st, int en, int l, int r) {
    if(en < l || st > r) // out of range, can't contribute
        return 0;
    if(l <= st && en <= r) // completely in range, can contribute
        return tree[node];
    int mid = (st+en)/2; // mid = (st+en)/2
    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,en,l,r);
    return q1+q2;
}

void update(int node, int st, int en, int ind, int val) { // 0 based index for arr
    if(st == en) {
        arr[st] = val; 
        tree[node] = val; 
        return;
    }
    int mid = (st+en)/2;
    if(ind <= mid)
        update(2*node,st,mid,ind,val);
    else
        update(2*node+1,mid+1,en,ind,val);
    tree[node] = tree[2*node]+tree[2*node+1]; // update back node based on child updates
}

int main()
{
    arr = {1,2,3,4,5,6,7,8,9,10};
    int n = arr.size();
    tree.resize(4*n);
    // Build
    build(1,0,n-1); // this builds the segment tree
    cout<<"Segment Tree:\n";
    for(int i = 0; i < 20; i++) {
        cout<<tree[i]<<" ";
    }cout<<endl;

    //Query
    int l = 1, r = 10; // use 0 based acc to code in query
    cout<<l<<"-"<<r<<":"<<query(1,0,n-1,l-1,r-1)<<endl;
    l = 1, r = 4; 
    cout<<l<<"-"<<r<<":"<<query(1,0,n-1,l-1,r-1)<<endl;
    l = 2, r = 6; 
    cout<<l<<"-"<<r<<":"<<query(1,0,n-1,l-1,r-1)<<endl;

    // Update
    update(1,0,n-1,0,101); // 0 based index
    update(1,0,n-1,2,303);

    for(auto it: arr) cout<<it<<" "; cout<<endl;
    l = 1, r = 10; // use 0 based acc to code in query
    cout<<l<<"-"<<r<<":"<<query(1,0,n-1,l-1,r-1)<<endl;
    l = 1, r = 4; 
    cout<<l<<"-"<<r<<":"<<query(1,0,n-1,l-1,r-1)<<endl;
    l = 2, r = 6; 
    cout<<l<<"-"<<r<<":"<<query(1,0,n-1,l-1,r-1)<<endl;

    return 0;
}