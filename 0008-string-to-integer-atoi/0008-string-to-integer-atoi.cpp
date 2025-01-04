class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0, sign = 1; long long ans = 0;
        while(i < n && s[i] == ' ') {i++;} // Step-1 removed leading white spaces 
        if(i < n && s[i] == '-' or s[i] == '+') {i++; if(s[i-1] == '-') {sign = -1;}} //Step-2 Determine sign
        while(i < n && s[i] == '0') {i++;} // 3.1 remove leading 0's Step 
        while(i < n) {
            if(s[i] < '0' or s[i] > '9') {return sign*ans;} // 3.2 If any unwanted char there
            ans *= 10; ans += (s[i] - '0'); i++;
            if(sign*ans > INT_MAX) {return INT_MAX;} // Step 4 if out of bound 
            if(sign*ans < INT_MIN) {return INT_MIN;}
        }
        cout<<"s:"<<sign;
        return sign*ans;
    }
};