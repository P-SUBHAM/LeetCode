// Approach 1: Implementation
// ans contains mention count
// whenever you get offline set offline time in active arr
// sort the events before processing
class Solution {
public:
    struct Compare{
        bool operator() (vector<string> a, vector<string> b) {
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if(t1 < t2) {
                return t1<t2;
            }
            else if(t1 > t2) {
                return t1<t2;
            }
            else { // timestamp is same so make offline come first
                if(a[0]=="OFFLINE") {
                    return true;
                }
                return false;
            }
            return true; // wont come here
         }
    };
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),Compare());
        int n = numberOfUsers;
        vector<int> ans(n,0);
        vector<int> active(n,0); // till till offline, if t >= ti then active
        for(auto event: events) {
            for(auto e: event) cout<<e<<" "; cout<<endl;
            int time = stoi(event[1]);
            if(event[0]=="MESSAGE") {
                if(event[2]=="ALL") {
                    for(int i = 0; i < n; i++) {
                        ans[i]++;
                    }
                }
                else if(event[2]=="HERE") { // activeTime only checked for HERE online
                    for(int i = 0; i < n; i++) {
                        if(time >= active[i]) {
                            ans[i]++;
                        }
                    }
                }
                else {
                    vector<int> ids;
                    string str = event[2]+" ";
                    int idno = 0;
                    for(auto ch: str) {
                        if(isdigit(ch)) {
                            idno*=10; idno+=ch-'0';
                        }
                        else if(ch == ' ') {
                            ids.push_back(idno);
                            idno = 0;
                        }
                    }
                    for(auto id: ids) { // if message override and mention
                        // if(time >= active[id]) {
                            ans[id]++;
                        // }
                    }
                }
            }
            else {
                int id = stoi(event[2]);
                active[id] = time+60;
            }
        }
        return ans;
    }
};