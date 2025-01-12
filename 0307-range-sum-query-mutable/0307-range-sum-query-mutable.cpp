// Approach 1: Segement Tree

// non-static member variables in C++ classes cannot be initialized inside classes so declared outside
// int N = 1e5+1;
// vector<int> tree(4*N);
// vector<int> a;
class NumArray {
    // class declartion 
    int N = 1e5+1;
    vector<int> tree = vector<int>(4*N, 0); // Initialize directly
    vector<int> a;
public:
    int n;
    void build(int node, int st, int en) {
        if(st == en) {
            tree[node] = a[st]; return;
        }
        int mid = (st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    NumArray(vector<int>& nums) {
        a.clear(); a = nums;
        n = nums.size();
        build(1,0,n-1);
    }

    void updateST(int node, int st, int en, int index, int val) {
        if(st == en) {
            a[st] = val;
            tree[node] = val; return;
        }
        int mid = (st+en)/2;
        if(index <= mid) {
            updateST(2*node,st,mid,index,val);
        }
        else {
            updateST(2*node+1,mid+1,en,index,val);
        }
        tree[node] = tree[2*node]+tree[2*node+1];
    }    
    void update(int index, int val) {
        updateST(1,0,n-1,index,val);
    }

    int query(int node, int st, int en, int l, int r) {
        if(en < l || st > r) {
            return 0;
        }
        if(l <= st && en <= r) {
            return tree[node];
        }
        int mid = (st+en)/2;
        return query(2*node,st,mid,l,r) + query(2*node+1,mid+1,en,l,r);
    }
    int sumRange(int left, int right) {
        return query(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */