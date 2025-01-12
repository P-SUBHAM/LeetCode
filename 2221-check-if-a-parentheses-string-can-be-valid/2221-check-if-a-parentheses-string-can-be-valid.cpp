// Approach 1: Greedy O(n)
// check closing c:) > o:opening + x( as x can be used as o '(' if req)
// odd len not possible
// once left iter and right iter (x from left can be used as ( if ) count increases, to do same from right we do right pass also after left pass 
class Solution {
public:
    bool valid(string s) {
        // cout<<"s:"<<s<<endl;
        int n = s.size();
        int o = 0, c = 0, x = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                o++;
            }
            else if(s[i] == ')') {
                c++;
            }
            else {
                x++;
            }
            if(c > o + x) {
                return false;
            }
        }
        return true;
    }
    bool canBeValid(string s, string locked) {
        string l = s, r;
        if(s.size()%2 == 1) { // odd length sequence cant be valid
            return false;
        }
        for(int i = 0; i < locked.size(); i++) {
            if(locked[i] == '0') {
                l[i] = 'x';
            }
        }
        r = l; reverse(r.begin(),r.end());
        for(auto &x: r) { // r is reverse(so r to l), {'(',')' swapped as seen from r}
            if(x == '(') {
                x = ')';
            }
            else if(x == ')') {
                x = '(';
            }
        }
        bool a = valid(l), b = valid(r);
        // cout<<a<<" "<<b<<endl;
        return a && b;
    }
};