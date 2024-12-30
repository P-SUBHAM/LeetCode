class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int ans = 0; int N = reservedSeats.size();
        set<int> st;
        for(int i = 0; i < N;) {
            int row = reservedSeats[i][0];
            st.insert(row);
            cout<<"row:"<<row<<endl;
            vector<int> v;
            while(i < N && reservedSeats[i][0] == row) {
                v.push_back(reservedSeats[i][1]);
                i++;
            }
            for(auto x: v) cout<<x<<" ";
            cout<<endl;
            int left = 0, mid = 0, right = 0;
            bool pos = true;
            for(int j = 2; j <= 5; j++) {
                if(find(v.begin(),v.end(),j) != v.end()) {
                    pos = false;
                }
            }
            if(pos) {
                left = 1;
            }
            pos = true;
            for(int j = 4; j <= 7; j++) {
                if(find(v.begin(),v.end(),j) != v.end()) {
                    pos = false;
                }
            }
            if(pos) {
                mid = 1;
            }
            pos = true;
            for(int j = 6; j <= 9; j++) {
                if(find(v.begin(),v.end(),j) != v.end()) {
                    pos = false;
                }
            }
            if(pos) {
                right = 1;
            }
            cout<<left<<mid<<right<<endl;
            if(left == 0) {
                ans += max(mid,right);
            }
            else {
                ans += (1 + right);
            }
        }
        ans += (n - st.size())*2;
        return ans;
    }
};