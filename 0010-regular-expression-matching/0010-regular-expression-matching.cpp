class Solution {
public:
    bool isMatch(string S, string P) {
        if(!P.size()) {
            return !S.size();
        }
        bool match = bool(S.size()) && (P[0] == S[0] or P[0] == '.');
        if(P.size() >= 2 and P[1] == '*') {
            return isMatch(S,P.substr(2,P.size()-1)) || (match && isMatch(S.substr(1,S.size()-1),P));
        }
        else {
            return match && isMatch(S.substr(1,S.size()-1),P.substr(1,P.size()-1));
        }
    }
};