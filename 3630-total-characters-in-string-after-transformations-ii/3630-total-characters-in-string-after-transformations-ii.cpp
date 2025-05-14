// Approach 1: Matrix Multiplication + Matrix exponentiation
class Solution {
public:
    static const int mod = 1e9+7;
    vector<vector<int>> matMul(vector<vector<int>> A, vector<vector<int>> B) {
        int m = A.size(), n = B.size(), q = B[0].size();
        vector<vector<int>> ans(m,vector<int>(q,0));
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < q; j++) {
                    ans[i][j] = (1ll*ans[i][j] + 1ll*A[i][k]*B[k][j])%mod;
                }
            }
        }
        return ans;
    }
    // Matrix exponentiation Iterative
    vector<vector<int>> matExp(vector<vector<int>> A, int t) {
        // return A^t
        int m = A.size(), n = A[0].size();
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(int i = 0; i < n; i++) ans[i][i] = 1;
        while(t) {
            int bit = t%2;
            t /= 2;
            if(bit == 1) {
                ans = matMul(A,ans);
            }
            A = matMul(A,A);
        } 
        return ans;
    }
    // Matrix exponentiation Recursive
    vector<vector<int>> matExpR(vector<vector<int>> A, int t) {
        int m = A.size(), n = A[0].size();
        if(t == 0) {
            vector<vector<int>> I(n,vector<int>(n,0));
            for(int i = 0; i < n; i++) I[i][i] = 1;
            return I;
        }
        if(t == 1) {
            return A;
        }
        vector<vector<int>> X = matExpR(A,t/2);
        X = matMul(X,X);
        if(t%2 == 1) {
            X = matMul(X,A);
        }
        return X;
    }
    void printMat(vector<vector<int>> A) {
        int m = A.size(), n = A[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout<<A[i][j]<<" ";
            }cout<<endl;
        }
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<int>> T(26,vector<int>(26,0));
        for(int j = 0; j < 26; j++) {
            for(int i = j+1; i <= j+nums[j]; i++) {
                T[j][i%26] = 1;
            }
        }
        vector<vector<int>> S(1,vector<int>(26,0));
        for(auto c: s) {
            S[0][c-'a']++;
        }
        // cout<<"S: \n"; printMat(S);
        // cout<<"T: \n"; printMat(T);
        vector<vector<int>> matexpv = matExp(T,t);
        // cout<<"MatExp: \n"; printMat(matexpv);
        vector<vector<int>> FS = matMul(S,matexpv);
        // cout<<"FS: \n"; printMat(FS);
        int ans = 0;
        auto comp = [&](int a, int b) {
            return (1ll*a+b)%mod;
        };
        return accumulate(FS[0].begin(),FS[0].end(),0,comp);
    }
};