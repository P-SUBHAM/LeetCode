// Approach 1: Heaps
class KthLargest {
public:
    int cap;
    priority_queue<int,vector<int>,greater<>> minpq;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(auto x: nums) {
            minpq.push(x);
            cap--;
            if(cap < 0) {
                minpq.pop();
                cap++;
            }
        }
    }
    
    int add(int x) {
        minpq.push(x);
        cap--;
        if(cap < 0) {
            minpq.pop();
            cap++;
        }
        return minpq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */