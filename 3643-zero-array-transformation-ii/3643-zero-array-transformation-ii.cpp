// Approach 2: BinarySearch on answer with Segment Tree with lazy Propagation range update
// 623/627 1577ms
class Solution16Mar2025 {
public:
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
    bool checkST(vector<int>& nums, vector<vector<int>>& queries, int k) {
        // return true;
        SegmentTree ST(nums); int n = nums.size();
        for(int i = 0; i < k; i++) {
            auto it = queries[i];
            int l = it[0], r= it[1], x = it[2];
            ST.rangeUpdate(1,0,n-1,l,r,-1*x);
        }
        // cout<<endl<<"k: "<<k<<"a: ";
        for(int i = 0; i < n; i++) {
            int val = ST.query(1,0,n-1,i,i);
            // cout<<val<<" ";
            if(val > 0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size(), low = 0, high = n, ans = n + 1;
        // cout<<n<<endl; //
        while(low <= high) {
            int k = low + (high - low) / 2;
            if(checkST(nums,queries,k)) {
                // cout<<endl<<k<<endl; // 
                ans = min(ans,k);
                high = k - 1;
            }
            else {
                low = k + 1;
            }
        }
        return (ans == n + 1) ? -1 : ans; 
    }
};

// Approach 1: Binary Search on answer + Scanline/Sweepline algo using struct events
// 623/627 passed; individual testcase all passing
class Solution15mar2025_03 {
public:
    struct Event {
        int ind;
        int x;
        Event (int ind_, int x_): ind(ind_), x(x_) {}
    };
    struct compare {
        bool operator() (Event &e1, Event &e2) {
            return e1.ind > e2.ind;
        }
    };
    // 626/627
    bool check2(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<Event> events; int en = events.size(), nn = nums.size();
        for(int i = 0; i < k; i++) {
            auto it = queries[i];
            int l = it[0], r = it[1], x = it[2];
            events.push_back(Event(l, x));
            events.push_back(Event(r + 1, -x));
        }

        // Sort events by index
        sort(events.begin(), events.end(), [](const Event& e1, const Event& e2) {
            return e1.ind < e2.ind;
        });

        int sum = 0, idx = 0, ans = 0;

        // Process events in sorted order
        for (int i = 0; i < nn; i++) {
            // Process all events that affect index i
            while (idx < en && events[idx].ind == i) {
                sum += events[idx].x;
                idx++;
            }
            
            if (sum < nums[i]) {
                ans++;
            }
        }

        return ans == 0;
    }
    // 624/627
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        priority_queue<Event, vector<Event>, compare> events;
        for(int i = 0; i < k; i++) {
            auto it = queries[i];
            int l = it[0], r = it[1], x = it[2];
            events.push(Event(l,x));
            events.push(Event(r+1,-1*x));
        }
        int sum = 0, ans = 0; 
        for(int i = 0; i < nums.size(); i++) {
            while(!events.empty() && events.top().ind == i) {
                auto it = events.top(); events.pop();
                sum += it.x;
            }
            // cout<<sum<<" ";
            if(sum < nums[i]) ans++;
        }
        return ans == 0;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size(), low = 0, high = n, ans = n + 1;
        cout<<n<<endl;
        while(low <= high) {
            int k = low + (high - low) / 2;
            if(check2(nums,queries,k)) {
                // cout<<endl<<k<<endl;
                ans = min(ans,k);
                high = k - 1;
            }
            else {
                low = k + 1;
            }
        }
        return (ans == n + 1) ? -1 : ans; 
    }
};



////////////////////////
// 15mar2025
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        auto canMakeZeroArray = [&](int k) {
            vector<int> diff(n + 1, 0);
            for (int i = 0; i < k; i++) {
                int left = queries[i][0], right = queries[i][1], val = queries[i][2];
                diff[left] += val;
                diff[right + 1] -= val;
            }
            int currVal = 0;
            for (int i = 0; i < n; i++) {
                currVal += diff[i];
                if (currVal < nums[i]) return false;
            }
            return true;
        };
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return 0;
        int left = 1, right = queries.size();
        if (!canMakeZeroArray(right)) return -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeZeroArray(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};