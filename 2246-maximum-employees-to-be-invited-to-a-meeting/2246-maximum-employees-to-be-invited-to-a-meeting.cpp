// Approach 1: Topological Sort/Kahn Algo+logic
// cycle len2+TailChain can be merged so add them together
// individual closed cycle individually so choose max among them
// Select best among above

// Algo use topo sort to find chain length ending at cycle node(for 2lencycle)
// indeg!=0 are cycle part, iterate through them to find cycle len = 2/>
// for cycle len 2, add chainlen[i],chain[adj[i]->j]
// chain[i] = chain from leaf to i including i
// for > 2 take max of closed circular cycle len

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size(); 
        vector<int> indeg(n);
        for(int x: favorite) indeg[x]++;
        // cout<<"Indeg:"; for(auto it: indeg) cout<<" "<<it; cout<<endl;
        queue<int> qu;
        for(int i = 0; i < n; i++)
            if(indeg[i]==0) qu.push(i);
        
        vector<int> chain(n,1);
        int d = 1;
        while(!qu.empty()) {
            int qusz = qu.size();
            for(int a=0; a<qusz; a++) { // mark next lev indeg as d+1
                int i = qu.front(); qu.pop();
                int j = favorite[i];
                chain[j] = max(chain[j],d+1);
                if(--indeg[j]==0) qu.push(j);
            }
            d++;
        }
        // cout<<"Indeg:"; for(auto it: indeg) cout<<" "<<it; cout<<endl;
        // cout<<"Chain:"; for(auto it: chain) cout<<" "<<it; cout<<endl;
        int maxCycle=0, join2cycle=0; //maxCycle for circular link, join2cycle for merged 2linkcycles
        for (int i=0; i<n; i++){
            if (indeg[i]==0) continue; //visited
            int cycleLen=0;
            for(int j=i; indeg[j]!=0; j=favorite[j]){
                indeg[j]=0;// mark as visited
                cycleLen++;
            }
            if (cycleLen>2) maxCycle=max(maxCycle, cycleLen);
            else join2cycle+=chain[i]+chain[favorite[i]];
        }
        return max(maxCycle,join2cycle);
    }
};