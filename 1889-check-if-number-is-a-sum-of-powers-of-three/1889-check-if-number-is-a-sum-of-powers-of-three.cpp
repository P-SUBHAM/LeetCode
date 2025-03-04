// Approach 2: BitManip
// represent n in ternary expression, check if it can be expressed as power of 3
class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> expression;
        while(n > 0) {
            if(n%3 == 2) return false; 
            // expression.push_back(n%3); 
            n /= 3;
        } 
        return true;
        reverse(expression.begin(),expression.end());
        for(auto it: expression) cout<<it<<" "; cout<<endl;
        for(auto it: expression) if(it == 2) return false;
        return true;
    }
};

// Approach 1: Recursion
// 3^x grows exponentially either include a power or skip it
class Solution1 {
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