// Approach 1: using Prefix product & lowerbound to find zero in arr
class ProductOfNumbers {
public:
    vector<int> prefix = {1};
    // set<int> zero;
    vector<int> zero;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        // if(num==0) {prefix.push_back(1); zero.insert(prefix.size()-1);}
        if(num==0) {prefix.push_back(1); zero.push_back(prefix.size()-1);}
        else prefix.push_back(prefix.back()*num);
    }
    
    int getProduct(int k) {
        // for(auto it: prefix) cout<<it<<" "; cout<<endl;
        int n = prefix.size();
        int tot = prefix.back();
        int excl = prefix[n-k-1];
        if(lower_bound(zero.begin(), zero.end(), n-k)!=zero.end()) {
            return 0;
        }
        int incl = tot/excl;
        return incl;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */