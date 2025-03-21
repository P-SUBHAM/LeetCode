// Approach 1: BFS+adj list
// convert each word to its pattern dot->*ot,d*t,do* and use the adj list to do bfs to find shortest route
class Solution {
public:
    map<string,vector<string>> adj;
    int bfs(string st, string en) {
        cout<<st<<" "<<en<<endl;
        queue<string> qu;
        qu.push(st); set<string> vis; vis.insert(st);
        int cnt = 0;
        while(!qu.empty()) {
            int sz = qu.size(); cnt++;
            while(sz--) {
                auto word = qu.front(); qu.pop();
                // cout<<word<<" "<<en<<" cnt:"<<cnt<<endl;
                if(word == en) return cnt;
                for(int i = 0; i < word.size(); i++) {
                    string str = "";
                    for(int l = 0; l < i; l++) {
                        str += word[l];
                    }
                    str += '*';
                    for(int r = i+1; r < word.size(); r++) {
                        str += word[r];
                    }
                    for(auto nei: adj[str]) {
                        if(!vis.count(nei)) {
                            qu.push(nei); vis.insert(nei);
                        }
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool endWordExist = false;
        for(auto word: wordList) {
            if(endWord == word) endWordExist = true;
            for(int i = 0; i < word.size(); i++) {
                string str = "";
                for(int l = 0; l < i; l++) {
                    str += word[l];
                }
                str += '*';
                for(int r = i+1; r < word.size(); r++) {
                    str += word[r];
                }
                adj[str].push_back(word);
            }
        }
        if(!endWordExist) return 0; // endword doesnt exist
        int ans = bfs(beginWord,endWord);
        return ans;
    }
};