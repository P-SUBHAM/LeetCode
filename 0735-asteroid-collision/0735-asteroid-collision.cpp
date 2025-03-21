// Approach 1 : Stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for(int i = 0; i < asteroids.size(); i++) {
            int x = asteroids[i];
            if(stack.size()==0) {
                stack.push_back(x);
            }
            else if(x > 0) {
                stack.push_back(x);
            }
            else { // x is -ve
                int y = stack.back();
                if(y < 0) { // if last ele also -ve
                    stack.push_back(x);
                }
                else {
                    if(abs(x) > abs(y)) {
                        stack.pop_back();
                        i--;
                    }
                    else if(abs(x) == abs(y)) {
                        stack.pop_back();
                    }
                    else {
                        // x destroyed
                    }
                }
            }
        }
        return stack;
    }
};