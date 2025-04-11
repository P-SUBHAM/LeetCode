class Solution {
public:
    bool isSymmetric(int x) {
        vector<int> v;
        while(x > 0) {
            v.push_back(x%10); x/=10;
        }
        int n = v.size();
        return n%2==0 && accumulate(v.begin(),v.begin()+n/2,0) == accumulate(v.begin()+n/2,v.end(),0);
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++) {
            if(isSymmetric(i)) {
                cnt++; //cout<<i<<endl;
            }
        }
        return cnt;
    }
};