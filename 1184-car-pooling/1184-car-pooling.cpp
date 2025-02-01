// Approach 1: scanline/sweepline based processing
// sort acc to start time and keep adding passenger
// before adding next passenger drop off earlier passeneger, and check cond
class Solution {
public:
    struct compareSt {
        bool operator()(vector<int> &a, vector<int> &b) {// Asc startTime ind1
            return a[1] < b[1];
        }
    };
    struct compareEn {
        bool operator()(vector<int> &a, vector<int> &b) {// Asc startTime ind1
            return a[2] > b[2];
        }
    };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        sort(trips.begin(),trips.end(),compareSt());
        priority_queue<vector<int>,vector<vector<int>>,compareEn> pq;
        int cap = 0;
        for(int i = 0; i < n; i++) {
            vector<int> v = trips[i];
            int p = v[0], s = v[1], e = v[2];
            // drop prev p before s
            while(!pq.empty() && pq.top()[2] <= s) {
                cap -= pq.top()[0]; pq.pop();
            } // dropable p droped, no more drop poss
            if(cap+p<=capacity) {
                cap += p;
                pq.push(v);
            }
            else {
                return false;
            }
        }
        return true;
    }
};