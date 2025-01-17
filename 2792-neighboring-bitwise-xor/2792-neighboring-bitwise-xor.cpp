// Approach 1:
// [a b c d] <- derived
// [0 a a^b a^b^c] a^b^c^d=0
// [1 1^a 1^a^b 1^a^b^c] {1^a^b^c^d = 1} => a^b^c^d = 0 
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(derived.begin(),derived.end(),0,[](int a, int b) {return a^b;}) == 0;
    }
};