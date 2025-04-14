class Solution
{
	public:
	vector<int> ans;
	map<int,int> indegree, outdegree;
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    ans.clear();
	    for(int i = 0; i < V; i++) {
	        for(auto it: adj[i]) {
	            outdegree[i]++;
	            indegree[it]++;
	        }
	    }
	    queue<int> pq;
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            pq.push(i);
	        }
	    }
	    while(!pq.empty()) {
	        int x = pq.front();
	        ans.push_back(x);
	        pq.pop();
	        for(auto it: adj[x]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                pq.push(it);
	            }
	        }
	    }
	    return ans;
	}
};
