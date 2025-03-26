// Approach 1: SweepLine Algorithm
// break into x and y interval, then break each interval into st and en, count if at any end interval there is no ongoing event
class Solution {
public:
    vector<vector<int>> extractInterval(int n, vector<vector<int>>& rectangles, bool isX) {
        vector<vector<int>> ans;
        for(auto coor: rectangles) {
            int st = 0, en = 0;
            if(isX) {
                st = coor[0], en = coor[2];
            }
            else {
                st = coor[1], en = coor[3];
            }
            ans.push_back({st,en});
        }
        return ans;
    }
    struct event {
        int coor = 0;
        bool isStart = true;
        event(int x_, bool isStart_): coor(x_), isStart(isStart_) {}
    };
    struct eventComparator {
        bool operator()(event e1, event e2) {
            if(e1.coor != e2.coor)
                return e1.coor < e2.coor;
            return e1.isStart < e2.isStart; // ending comes first
        }
    };
    int countIntervalCuts(vector<vector<int>> &xInterval) {
        vector<event> xEvents;
        for(auto interval: xInterval) {
            xEvents.push_back(event(interval[0],true));
            xEvents.push_back(event(interval[1],false));
        }
        sort(xEvents.begin(),xEvents.end(),eventComparator());
        int xCuts = 0; int start = 0;
        for(auto event: xEvents) {
            if(event.isStart) {
                start++;
            }
            else {
                start--;
                if(start == 0) {
                    xCuts++;
                }
            }
        }
        return xCuts - 1;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xInterval = extractInterval(n,rectangles,true);
        vector<vector<int>> yInterval = extractInterval(n,rectangles,false);

        int xCuts = countIntervalCuts(xInterval);
        int yCuts = countIntervalCuts(yInterval);

        cout<<xCuts<<" "<<yCuts<<endl;

        return (xCuts >= 2 || yCuts >= 2);
    }
};