// Approach 2: fenwick tree
// point update, range query (default behavior)
// range update, point query (diff array behavior) ftree.update(i+1,x-ftree.query(i)); 
class Solution {
public:
    struct FenwickTree { // ind 1 to n
        vector<long long> fenw;
        int n;
        FenwickTree(int n_):n(n_) {fenw.resize(n+3,0);}
        long long query(int ind) { // prefix sum 1..ind
            long long sum = 0;
            for(; ind > 0; ind -= ind&-ind) {
                sum += fenw[ind];
            }
            return sum;
        }
        void update(int ind, int diff) { // point update
            for(; ind <= n; ind += ind&-ind) {
                fenw[ind] += diff;
            }
        }
    };
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> mp2;
        for(int i = 0; i < n; i++) {
            mp2[nums2[i]] = i;
        }
        FenwickTree ftree(n);
        ftree.update(mp2[nums1[0]]+1,1);
        long long ans = 0;
        for(int i1 = 1; i1 < n; i1++) {
            int x = nums1[i1];
            int i2 = mp2[x];
            long long commleft = ftree.query(i2+1);
            long long uncommleft = i1 - commleft;
            long long commright = (n-1)-(i2+1)+1 - uncommleft;
            ans += commleft * commright;
            ftree.update(i2+1,1);
        }
        return ans;
    }
};

//Approach 1: Segment tree
/* see keep adding the index in nums2 into segtree(by adding 1 at the index) to denote that 
while iterating in nums1 all these index of nums2 element are seen, and sum of elemenets in the range l,r of nums2 says how many elemenets of nums2 have already been seen by nums1 i.e on left of i1 how many elements are matching in the range(based on mid no index in nums2) for nums2.
*/
class Solution1 {
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