//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
    int timer = 1;
    void dfsArticulationPt(int V, vector<int> adj[],
    int src, int parent, vector<int> &tin, vector<int> &low,
    vector<int> &artPt) {
        tin[src] = low[src] = timer++;
        int child = 0;
        for(auto nei: adj[src]) {
            if(nei == parent) continue;
            if(tin[nei] == -1) {
                dfsArticulationPt(V,adj,nei,src,tin,low,artPt);
                child++;
                // if its = means it can from node, 
                // so it would be articulation 
                // p!=-1 as could be single parent
                if(low[nei] >= tin[src] && parent != -1) { 
                    artPt[src] = 1;
                }
                low[src] = min(low[src],low[nei]);
            }
            else {
                // if visited in articulation
                low[src] = min(low[src],tin[nei]); 
            }
        }
        if(child > 1 && parent == -1) { // multiple child parent
            artPt[src] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> tin(V,-1);
        vector<int> low(V,-1);
        vector<int> artPt(V,-1);
        timer = 0;
        for(int i = 0; i < V; i++) {
            if(tin[i]==-1) {
                dfsArticulationPt(V,adj,i,-1,tin,low,artPt);
            }
        }
        vector<int> articulationPtList;
        for(int i = 0; i < V; i++) {
            if(artPt[i] == 1) {
                articulationPtList.push_back(i);
            }
        }
        if(articulationPtList.size() == 0) return {-1};
        return articulationPtList;
    }
};


//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
