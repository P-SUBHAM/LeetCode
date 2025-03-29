// VeryHard
// Approach 1: NextGreater,Power,Logic,MonotonicStack, factorisation
// Find prime score, find support len, sort and check max value
class Solution {
public:
    int getPrimeScore(int x) {
        if(x==1) return 0;
        // cout<<x<<":";
        int i = 2, cnt = 0;
        while(i*i <= x) {
            if(x%i == 0) {
                cnt++;
                while(x%i == 0) {
                    x /= i;
                }
                // cout<<i<<" ";
            }
            i++;
        }
        if(x > 1) cnt++; // incase of 9
        // cout<<x<<endl;
        return cnt;
    }
    vector<int> getPrimeScoreArr(vector<int>& nums) {
        vector<int> primeScoreArr;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int ps = getPrimeScore(nums[i]);
            primeScoreArr.push_back(ps);
        }
        return primeScoreArr;
    }
    vector<int> getNextRightGreaterIndex(vector<int> nums) {
        nums.push_back(INT_MAX);
        int n = nums.size();
        vector<int> nextGreaterArr(n-1);
        stack<int> decSt;
        for(int i = 0; i < n; i++) {
            while(!decSt.empty() && nums[i] > nums[decSt.top()]) {
                int prevInd = decSt.top(); decSt.pop();
                nextGreaterArr[prevInd] = i;
            }
            decSt.push(i);
        }
        return nextGreaterArr;
    }
    vector<int> getPrevGreaterIndex(vector<int> nums) {
        int n = nums.size();
        vector<int> prevGreaterArr(n);
        stack<int> decSt;
        for(int i = 0; i < n; i++) {
            while(!decSt.empty() && nums[i] > nums[decSt.top()]) {
                int prevInd = decSt.top(); decSt.pop();
            }
            if(!decSt.empty()) {
                prevGreaterArr[i] = decSt.top();
            }
            else {
                prevGreaterArr[i] = -1;
            }
            decSt.push(i);
        }
        return prevGreaterArr;
    }
    int power(int b, int p) {
        int mod = 1e9+7;
        if(p == 0) return 1;
        if(p == 1) return b%mod;
        int x = power(b,p/2);
        if(p%2 == 1) {
            int ans = (1LL * x * b)%mod;
            ans = (1LL*ans*x)%mod;
            return ans;
        }
        return (1LL * x * x)%mod;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScoreArr = getPrimeScoreArr(nums);
        // for(auto it: primeScoreArr) cout<<it<<" "; cout<<endl;
        vector<int> nextRightGreaterIndex = getNextRightGreaterIndex(primeScoreArr);
        vector<int> prevGreaterIndex = getPrevGreaterIndex(primeScoreArr);
        // for(auto it: nextRightGreaterIndex) cout<<it<<" "; cout<<endl;
        // for(auto it: prevGreaterIndex) cout<<it<<" "; cout<<endl;
        vector<vector<long long>> maxScoreArr;
        for(int i = 0; i < n; i++) {
            int no = nums[i];
            long long cnt = 0;
            cnt = 1LL*(nextRightGreaterIndex[i]-i)*(i-prevGreaterIndex[i]); // as they are excl boundary
            if(cnt > INT_MAX) cnt = 1e9+2; // as k max 1e9;
            maxScoreArr.push_back({no,cnt});
        }
        sort(maxScoreArr.begin(),maxScoreArr.end(),greater<>());
        // for(auto pair: maxScoreArr) {
        //     cout<<pair[0]<<":"<<pair[1]<<endl;
        // }
        int ans = 1;
        int mod = 1e9+7;
        long long K = 1LL*k;
        for(int i = 0; i < n; i++) {
            int no = maxScoreArr[i][0];
            int cnt = maxScoreArr[i][1];
            if(K > cnt) {
                // cout<<no<<"^"<<cnt<<endl;
                ans = (1LL * ans * power(no,cnt))%mod;
                // cout<<ans<<endl;
                K -= cnt;
            }
            else if(K > 0) {
                // cout<<no<<"^"<<k<<endl;
                ans = (1LL * ans * power(no,K))%mod;
                // cout<<ans<<endl;
                break;
            }
        }
        return ans;
    }
};