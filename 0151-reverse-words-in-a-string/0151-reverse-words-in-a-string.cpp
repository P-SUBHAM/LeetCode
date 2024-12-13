class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string word = "", ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ' && word == "") {
                continue;
            }
            else if(s[i] == ' ') {
                reverse(word.begin(),word.end());
                if(ans != "") {
                    ans += " " + word;
                }
                else {
                    ans += word;
                }
                word = "";
            }
            else {
                word += s[i];
            }
        }
        if(word != "") {
            reverse(word.begin(),word.end());
            if(ans != "") {
                ans += " " + word;
            }
            else {
                ans += word;
            }
            
        }
        return ans;
    }
};