// Approach 1: Scanline algo
// keep checking logs and add req time to respective fid
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        map<int,int> func; int functime = 0;
        stack<vector<int>> st;
        for(int i = 0; i < logs.size(); i++) {
            string log = logs[i];
            int i1, i2;
            for(int i = 0; i < log.size(); i++) if(log[i]==':') {i1=i;break;}
            for(int i = log.size()-1; i >= 0; i--)if(log[i]==':'){i2=i;break;}
            int fid = stoi(log.substr(0,i1));
            int tst = stoi(log.substr(i2+1,log.size()-1-(i2+1)+1));
            cout<<fid<<" "<<tst<<endl;
            if(st.empty()) {
                st.push({fid,tst,0});
            }
            else {
                if(log[i1+1]=='s') { // st type
                    st.push({fid,tst,0});
                }
                else { // en type
                    int timedur = tst-st.top()[1]+1-st.top()[2]; // sub incl func time dur to-do
                    int extra = st.top()[2];
                    cout<<timedur<<endl;
                    func[fid] += timedur; st.pop();
                    if(!st.empty()) {
                        auto v = st.top(); st.pop(); // for modifying the parent pro
                        v[2] += timedur+extra;
                        cout<<"t:"<<v[2]<<endl;
                        st.push(v);
                    }
                }
            }
        }
        vector<int> ans;
        for(auto pair: func) {
            int fid = pair.first, ftime = pair.second;
            ans.push_back(ftime);
        }
        return ans;
    }
};

// Approach is not corret
class Solution11 {
public:
    int functime;
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        functime = 0;
        map<int,int> func; // func id: time spent
        map<int,stack<int>> st; //map func id: stack<st> time
        for(auto log: logs) {
            int i1, i2;
            for(int i = 0; i < log.size(); i++) if(log[i]==':') {i1=i;break;}
            for(int i = log.size()-1; i >= 0; i--) if(log[i]==':') {i2=i;break;}
            int fid = stoi(log.substr(0,i1));
            int tst = stoi(log.substr(i2+1,log.size()-1-(i2+1)+1));
            // cout<<fid<<" "<<en<<endl;
            if(log[i1+1]=='s') {//start type
                st[fid].push(tst);
            }
            else { // end type
                int sttime = st[fid].top(); st[fid].pop();
                int ans = tst-sttime+1-functime;
                functime+=ans;
                func[fid]+=ans;
            }
        }
        vector<int> ans;
        for(auto pair: func) {
            int fid = pair.first, ftime = pair.second;
            ans.push_back(ftime);
        }
        return ans;
    }
};