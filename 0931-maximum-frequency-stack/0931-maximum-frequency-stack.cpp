// Approach 1: map<freq,stack<>>
// freq ele : [5],[7],[5],[7],[4],[5]
// 1 : 5 7 4
// 2 : 5 7
// 3 : 5
class FreqStack {
public:
    int maxfreq;
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> freqstack; // main stack ds
    FreqStack() {
        maxfreq = 0;
        freqstack.clear();
    }
    
    void push(int val) {
        int f = ++freq[val];
        freqstack[f].push(val);
        if(f > maxfreq) maxfreq = f;
    }
    
    int pop() {
        if(maxfreq==0) return -1;
        int val = freqstack[maxfreq].top(); freqstack[maxfreq].pop();
        if(freqstack[maxfreq].empty()) {
            maxfreq--;
        }
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */