//Approach 1: Segment tree
class Solution {
public:
    struct SegmentTree {
        vector<long long> tree;
        int n;
        SegmentTree(int n_): n(n_) {tree.resize(4*n);}
        void pointUpdate(int node, int st, int en, int ind, int val) {
            if(st == en && st == ind) {
                tree[node] = val; return;
            }
            int mid = st + (en-st)/2;
            if(ind <= mid) pointUpdate(2*node,st,mid,ind,val);
            else pointUpdate(2*node+1,mid+1,en,ind,val);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
        long long query(int node, int st, int en, int l, int r) {
            if(st > r || en < l) return 0;
            if(l <= st && en <= r) return tree[node];
            int mid = (st+en)/2;
            long long q1 = query(2*node,st,mid,l,r), q2 = query(2*node+1,mid+1,en,l,r);
            tree[node] = tree[2*node] + tree[2*node+1];
            return q1+q2;
        }
    };
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> mp2;
        for(int i = 0; i < n; i++) {
            mp2[nums2[i]] = i;
        }
        SegmentTree segtree(n);
        segtree.pointUpdate(1,0,n-1,mp2[nums1[0]],1);
        long long ans = 0;
        for(int i1 = 1; i1 < n; i1++) {
            int x1 = nums1[i1];
            int i2 = mp2[x1]; // index of x in nums2
            long long commleft = segtree.query(1,0,n-1,0,i2);
            long long uncommleft = i1 - commleft;
            long long commright = (n-1)-(i2+1)+1 - uncommleft;
            ans += commleft * commright;
            segtree.pointUpdate(1,0,n-1,i2,1);
        }
        return ans;
    }
};