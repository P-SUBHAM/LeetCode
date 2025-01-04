class Solution {
public:
    int myAtoi(string s) {
        string str = ""; bool num = false, sym = false;
        for(auto c: s) {
            if(c == ' ' && !sym && !num) {}
            else if(c == '-' && !sym) {if(num) {break;} sym = true; str+='-';}
            else if(c == '+' && !sym) {if(num) {break;} sym = true;}
            else if(c < '0' or c > '9') {break;}
            else if(c == '0' && !num) {sym=true;}
            else {str += c; num = true;}
        }
        cout<<str<<endl;
        if(str == "" or str == "+" or str == "-") return 0;
        int len = str.size();
        if(len >= 14) {
            if(s[0] == '-') {
                return -1*(1ll<<31);
            }
            else {
                return (1ll<<31) - 1;
            }
        }
        long long x = stoll(str);
        if(x > (1ll<<31) - 1) {
            x = (1ll<<31) - 1;
        }
        else if(x < -1ll*1<<31) {
            x = -1*(1ll<<31);
        }
        // cout << x << endl;
        return x;
    }
};