// Approach 1: logic: even occurences can be set in as palindrome, 
// odd can be set as palindrome only once per string in middle, so check if odd occur <= k
// handle case pallindrome cant be empty
class Solution {
public:
    bool canConstruct(string s, int k) {
        int oddoccur = 0, evenoccur = 0;
        map<char,int> cnt;
        for(auto c: s) {
            cnt[c]++;
            if(cnt[c]%2 == 1) {
                oddoccur++; 
            }
            if(cnt[c]%2 == 0) {
                oddoccur--; evenoccur++;
            }
        }
        cout<<oddoccur<<evenoccur<<k<<endl;
        if(oddoccur > k) {
            return false;
        }
        if(evenoccur*2+oddoccur >= k) {
            return true;
        }
        return false;
    }
};