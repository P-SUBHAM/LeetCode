class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int frequencies[2][128] = {};
        frequencies[0]['a'] = frequencies[0]['e'] = frequencies[0]['i'] = frequencies[0]['o'] = frequencies[0]['u'] = 1;

        long long response = 0;
        int currentK = 0, vowels = 0, extraLeft = 0, left = 0;

        for (int right = 0; right < word.length(); right++) {
            char rightChar = word[right];

            if (frequencies[0][rightChar]) {
                if (++frequencies[1][rightChar] == 1) vowels++;
            } else {
                currentK++;
            }

            while (currentK > k) {
                char leftChar = word[left++];
                if (frequencies[0][leftChar]) {
                    if (--frequencies[1][leftChar] == 0) vowels--;
                } else {
                    currentK--;
                }
                extraLeft = 0;
            }

            while (vowels == 5 && currentK == k && left < right && frequencies[0][word[left]] && frequencies[1][word[left]] > 1) {
                extraLeft++;
                frequencies[1][word[left++]]--;
            }

            if (currentK == k && vowels == 5) {
                response += (1 + extraLeft);
            }
        }

        return response;
    }
};

// Approach 1: Binary Search on Answer
// Do BS on ans, for no of substrings possible, the use check function to determine if pos or not
// To-fix
class Solution1 {
public:
    bool vowf(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    bool check(string &word, int k, int cnt) {
        int n = word.size(), sn = n - cnt + 1, ans = 0;
        if(sn < 5 + k) return false;
        set<char> st; 
        multiset<char> tot;
        int vow = 0; int i = 0;
        for(; i < sn; i++) {
            char ch = word[i];
            if(vowf(ch)) {
                st.insert(ch); vow++; tot.insert(ch);
            }
        }
        if(st.size()==5 && sn - vow == k) {
            ans++;
        }
        int x = cnt; 
        while(x--) {
            char chadd = word[i];
            char chrm = word[i-sn];
            i++;
            if(vowf(chadd)) {
                vow++;
                tot.insert(chadd); 
                st.insert(chadd);
            } 
            if(vowf(chrm)) {
                vow--;
                tot.erase(tot.find(chrm));
                if(tot.count(chrm)==0) st.erase(chrm);
                if(st.size()==5 && sn - vow == k) ans++;
            }
        }
        cout<<cnt<<":"<<ans<<endl;
        return ans >= cnt;
    }
    long long countOfSubstrings(string word, int k) {
        long long l = 1, n = word.size(),r = n-5+1, ans = 0;
        while(l <= r) {
            long long mid = (l+r)/2;
            if(check(word,k,mid)) {
                ans = max(ans,mid);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};