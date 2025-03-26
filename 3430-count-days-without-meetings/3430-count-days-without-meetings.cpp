// Approach 1: Greedy
// sort meeting by start time, and check meetduration for interval and subtract from total days
class Solution {
public:
    struct comparator {
        bool operator()(vector<int> &meet1, vector<int> &meet2) {
            if(meet1[0] < meet2[0]) 
                return true;
            else if(meet1[0] == meet2[0]) 
                return meet1[1] <= meet2[1];
            else 
                return false;
            return true;
        }
    };
    int countDays(int days, vector<vector<int>>& meetings) {
        int daysWithoutMeeting = days;
        int n = meetings.size();
        sort(meetings.begin(),meetings.end(),comparator());
        daysWithoutMeeting -= (meetings[0][1] - meetings[0][0] + 1);
        int prevMeetEnd = meetings[0][1];
        for(int i = 1; i < n; i++) { // 1-3 4-5; 1-3 5-7; || 1-3 2-5; 1-3 3-5; 
            int st = meetings[i][0], en = meetings[i][1];
            int MeetDur = 0;
            if(en <= prevMeetEnd) continue;
            if(st > prevMeetEnd) {
                MeetDur = en - st + 1;
            }
            else {
                MeetDur = en - prevMeetEnd;
            }
            MeetDur = MeetDur;
            // cout<<MeetDur<<endl;
            prevMeetEnd = en;
            daysWithoutMeeting -= MeetDur;
        }
        return daysWithoutMeeting;
    }
};