// Approach 1: segment tree
// for each num in start search max right index in range >=num,end 
class Solution {
public:
    struct SegmentTree {
        vector<int> tree;
        int n;
        SegmentTree(int n_):n(n_) {tree.resize(4*n);}
        void update(int node, int st, int en, int ind, int val) {
            if(st == en && st == ind) {
                tree[node] = val; return;
            }
            int mid = (st+en)/2;
            if(ind <= mid) update(2*node,st,mid,ind,val);
            else update(2*node+1,mid+1,en,ind,val);
            tree[node] = max(tree[2*node],tree[2*node+1]);
        }
        int query(int node, int st, int en, int l, int r) {
            if(en < l || st > r) return INT_MIN;
            if(l <= st && en <= r) return tree[node];
            int mid = (st+en)/2;
            int q1 = query(2*node,st,mid,l,r);
            int q2 = query(2*node+1,mid+1,en,l,r);
            tree[node] = max(tree[2*node],tree[2*node+1]);
            return max(q1,q2);
        }
    };

    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int N = 5e4;
        SegmentTree segtree(N+1);
        unordered_map<int,int> mp;

        for(int i = n-1; i >= 0; i--) {
            int x = nums[i];
            if(mp.find(x) == mp.end()) {
                mp[x] = i;
                segtree.update(1,0,N,x,i);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            int ind = segtree.query(1,0,N,x,N);
            ans = max(ans,ind-i);
        }
        return ans;
    }
};