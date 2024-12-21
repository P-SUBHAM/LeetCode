class Solution {
public:
    unordered_map<char,string> mpp = {
                {'2',"abc"},{'3',"def"},
        {'4',"ghi"},{'5',"jkl"},{'6',"mno"},
        {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        vector<string> v;
        int n = digits.size();
        if(n == 0) {
            return v;
        }
        if(n == 1) {
            for(auto it: mpp[digits[0]]) {
                // converting char to string
                v.push_back(string(1,it));
            }
            return v;
        }
        vector<string> rightComb = letterCombinations(digits.substr(1,n-1));
        for(auto it: mpp[digits[0]]) {
            for(auto it2: rightComb) {
                v.push_back(it + it2);
            }
        }
        return v;
    }
};