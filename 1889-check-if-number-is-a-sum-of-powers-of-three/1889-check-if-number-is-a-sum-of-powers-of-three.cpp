class Solution {
public:
    bool power3(int n, int x) {
        if(pow(3,x) > n) return false;
        if(pow(3,x) == n) return true;
        return power3(n-pow(3,x),x+1) || power3(n,x+1);
    }
    bool checkPowersOfThree(int n) {
        return power3(n,0);
    }
};