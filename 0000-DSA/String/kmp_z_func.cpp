class Solution {
    public:
      // kmp prefix array
      // prefix[j-1] gives index to next check 0 based i.e all prev ele are already prefix matched
      vector<int> prefix_func(string s) {
          int n = s.size();
          vector<int> prefix(n,0);
          for(int i = 1; i < n; i++) {
              int j = prefix[i-1];
              while(j > 0 && s[i]!=s[j]) {
                  j = prefix[j-1];
              }
              if(s[i] == s[j]) {
                  j++;
              }
              prefix[i] = j;
          }
          return prefix;
      }
  
      //kmp
      vector<int> KMP_func(string a, string b) { // check b(part) in a(main)
          int pos = -1;
          vector<int> prefix = prefix_func(b);
          vector<int> occur;
          int i = 0, j = 0;
          // assume aabaa is matched in a j=5->pre[4]=2
          while(i < a.size()) { // while loop preferable
              if(a[i] == b[j]) {
                  i++; j++;
              }
              else {
                  if(j > 0) {
                      j = prefix[j-1];
                  }
                  else {
                      i++;
                  }
              }
              if(j == b.size()) {
                  pos = i - b.size();
                  occur.push_back(pos);
                  j = prefix[j-1];
              }
          }
          return occur;
      }
      // string matching using pattern+string concat, as in z func using kmp prefix arr
      vector<int> KMP_Z_func(string txt, string pat) {
          string comb = pat + "$" + txt;
          vector<int> prefix = prefix_func(comb);
          int patSz = pat.size();
          vector<int> pos;
          for(int i = 0; i < comb.size(); i++) {
              if(prefix[i] == patSz) {
                  pos.push_back(i-patSz+1-patSz-1);
              }
          }
          return pos;
      }
      // z array function
      vector<int> getZarr(string s) {
          int n = s.size();
          vector<int> z(n);
          int l = 0, r = 0;
          for(int i = 1; i < n; i++) {
              if(i < r) {
                  z[i] = min(z[i-l],r-i); // r-i is max len poss till end
              }
              while(i+z[i] < n && s[z[i]] == s[i+z[i]]) {
                  z[i]++;
              }
              if(i+z[i] > r) {
                  l = i;
                  r = i + z[i];
              }
          }
          return z;
      }
      // z function string matching
      vector<int> Z_function(string txt, string pat) {
          string comb = pat + "$" + txt;
          vector<int> zarr = getZarr(comb);
          int patSz = pat.size();
          vector<int> pos;
          for(int i = 0; i < zarr.size(); i++) {
              if(zarr[i] == patSz) {
                  pos.push_back(i-patSz-1);
              }
          }
          return pos;
      }
      vector<int> search(string& pat, string& txt) {
          // vector<int> ans = KMP_func(txt,pat);
          // vector<int> ans = KMP_Z_func(txt,pat);
          vector<int> ans = Z_function(txt,pat);
          return ans;
      }
  };