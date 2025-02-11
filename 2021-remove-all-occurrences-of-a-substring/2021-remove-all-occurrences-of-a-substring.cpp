// Approach 1: brute + stl
class Solution {
public:
    string removeOccurrences(string s, string part) {
        // while( s.find(part) != string::npos ) s.erase(s.find(part), part.length()); // string::npos = -1
        while( s.find(part) != -1 ) s.erase(s.find(part), part.length());
        return s;
    }
};