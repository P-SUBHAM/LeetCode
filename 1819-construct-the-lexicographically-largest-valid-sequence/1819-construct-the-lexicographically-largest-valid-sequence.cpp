// Approach 1: BackTracking
// select the leftmost open index and choose from max num 
// select and recurse/backtrack to find the lexicographically largest permutation
class Solution {
public:
    int cnt = 0;
    bool rec(vector<int> &v, set<int> &num, set<int> &pos) {
        cnt++;
        if(num.size()==0) {
            return true;
        }
        set<int> numst = num;
        for(auto rit = numst.rbegin(); rit!=numst.rend(); rit++) {
            int no = *rit; num.erase(no);
            if(no==1) {
                int a = *pos.begin(); 
                v[a] = 1; pos.erase(a);
                if(rec(v,num,pos)) return true;
                v[a] = 0; pos.insert(a);
            }
            else {
                int a = *pos.begin(), b = a + no; 
                if(pos.find(b)==pos.end()) {num.insert(no); continue;} // if u continue without inserting back num it will cause issue
                v[a] = v[b] = no; pos.erase(a); pos.erase(b);
                if(rec(v,num,pos)) return true;
                v[a] = v[b] = 0; pos.insert(a); pos.insert(b);
            }
            num.insert(no); 
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        if(n==1) return {1};
        vector<int> v(2*n-1);
        set<int> num; // no being used 1,2,2,3,3...n,n
        set<int> pos; // array pos 0,1,2,...,2*n-1
        for(int i = 1; i <= n; i++) num.insert(i);
        for(int i = 0; i < 2*n-1; i++) pos.insert(i);
        for(int i = n; i >= 0; i--) {
            num.erase(i);
            if(i==1) {
                int a = *pos.begin(); 
                v[a] = i; pos.erase(a);
                if(rec(v,num,pos)) return v;
                v[a] = 0; pos.insert(a);
            }
            else {
                int a = *pos.begin(); int b = a + i;
                if(pos.find(b)==pos.end()) continue;
                v[a] = v[b] = i;  pos.erase(a); pos.erase(b);
                if(rec(v,num,pos)) return v;
                v[a] = v[b] = 0; pos.insert(a); pos.insert(b);
            }
            num.insert(i);
        }
        return v;
    }
};

//////////// trial below \/

// This code tries to put n,n-1,.. from left to right but not the correct greedy soln
// op: [9,4,8,5,7,4,1,6,5,9,8,7,3,6,2,3,2]
// exp: [9,7,5,3,8,6,3,5,7,9,4,6,8,2,4,2,1]
class SolutionT2 {
public:
    set<vector<int>> ans;
    int cnt = 1;
    bool rec(vector<int> &v, set<int> &st, int n) {
        cnt++;
        if(n==1) {
            int a = *st.begin();
            v[a] = 1; 
            return true;
        }
        set<int> tempst = st;
        for(auto it: tempst) {
            int a = it, b = a + n;
            if(st.find(b)==st.end()) {
                continue;
            }
            else {
                st.erase(a); st.erase(b);
                v[a] = n, v[b] = n;
                if(rec(v,st,n-1)) return true;
                v[a] = 0, v[b] = 0;
                st.insert(a); st.insert(b);
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        if(n==1) return {1};
        ans.clear();
        vector<int> v(2*n-1);
        set<int> st;
        for(int i = 0; i < 2*n-1; i++) {
            st.insert(i);
        }
        for(int i = 0; i+n < 2*n-1; i++) {
            int a = i, b = i+n;
            v[a] = n; v[b] = n;
            st.erase(a); st.erase(b);
            if(rec(v,st,n-1)) {
                cout<<"cnt:"<<cnt<<endl;
                return v;
            }
            st.insert(a); st.insert(a);
            v[a] = 0; v[b] = 0;
        }
        cout<<"cnt:"<<cnt<<endl;
        return v;
    }
};

// Because we are calculating all possibilities TLE
class SolutionT1 {
public:
    set<vector<int>> ans;
    int cnt = 1;
    void rec(vector<int> &v, set<int> &st, int i, int n) {
        cnt++;
        if(i==n) {
            int a = *st.begin(), b = *st.rbegin();
            if(b-a==i) {
                v[a] = i, v[b] = i; ans.insert(v);
            }
            else {
                return;
            }
        }
        set<int> tempst = st;
        for(auto it: tempst) {
            int a = it, b = a + i;
            if(st.find(b)==st.end()) {
                continue;
            }
            else {
                st.erase(a); st.erase(b);
                v[a] = i, v[b] = i;
                rec(v,st,i+1,n);
                v[a] = 0, v[b] = 0;
                st.insert(a); st.insert(b);
            }
        }
    }
    vector<int> constructDistancedSequence(int n) {
        if(n==1) return {1};
        ans.clear();
        vector<int> v(2*n-1);
        set<int> st;
        for(int i = 0; i < 2*n-1; i++) {
            st.insert(i);
        }
        for(int i = 0; i < 2*n-1; i++) {
            v[i] = 1;
            st.erase(i);
            rec(v,st,2,n);
            st.insert(i);
            v[i] = 0;
        }
        cout<<"cnt:"<<cnt<<endl;
        return *ans.rbegin();
    }
};