// Approach 1: count no of setbits in num2, that many bits u need to toggle in num1
// change 1->0 for msb and 0->1 for lsb 0 pos
class Solution {
public:
    int no_of_bits(int n) {
        int k = 0;
        while(n > 0) {
            k += (n&1);
            n >>= 1;
        }
        return k;
    }
    int minimizeXor(int num1, int num2) {
        int k1 = no_of_bits(num1),k2 = no_of_bits(num2), x = 0;
        // finally modify k2 bits in num1 k2=set+unset;
        int unsetb = min(k1,k2);
        int setb = max(0,k2-unsetb);
        cout<<setb<<" "<<unsetb<<endl;
        // int i = 31-__builtin_clz(num1) pos of msb 0 based
        // __builtin_clz(x) no of leading 0, (tot 32 bits)
        for(int i = 31-__builtin_clz(num1); i>= 0 && unsetb > 0; i--) {
            if(((num1>>i)&1) == 1) {
                x ^= (1<<i);
                unsetb--;
            }
        }
        for(int i = 0; i < 32 && setb > 0; i++) {
            if(((num1>>i)&1) == 0) {
                x ^= (1<<i);
                setb--;
            }
        }
        return x;
    }
};