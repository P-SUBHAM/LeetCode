class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> v; int x = 0; char last = chars[0];
        for(auto c: chars) {
            // cout<<" -:"<<c;
            if(c!=last) {
                v.push_back(last);
                // cout<<last<<":"<<x<<" ";
                if(x!=1) {
                    string s = to_string(x);
                    for(auto it: s) {
                        v.push_back(it);
                    }
                } 
                last = c;
                x = 1;
            }
            else {
                x++;
            }
        }
        v.push_back(last);
        cout<<x<<" ";
        if(x!=1) {
            // cout<<last<<":"<<x<<" ";
            string s = to_string(x);
            for(auto it: s) {
                v.push_back(it);
            }
        }
        chars = v;
        return v.size();
    }
};