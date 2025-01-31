// Approach 2: graph traversal, component no and size.
//1. iterate and calculate component:component_size
//2. iterate once again and see by adding 1 how much area can you make,(ret glo max)
class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    // traverses graph and marks cells as compno, returns size of comp
    int compdfs(int r,int c,int cno,vector<vector<int>>& grid,int n) {
        int sz = 0;
        stack<vector<int>> st; st.push({r,c}); grid[r][c] = cno; sz++;
        while(!st.empty()) {
            auto node = st.top(); st.pop();
            int i = node[0], j = node[1];
            for(auto dir: dirs) {
                int nx = i+dir[0], ny = j+dir[1];
                if(0<=nx&&nx<n&&0<=ny&&ny<n&&grid[nx][ny]==1) {
                    st.push({nx,ny}); grid[nx][ny] = cno; sz++;
                }
            }
        }
        return sz;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), compno = 2, ans = 1;
        unordered_map<int,int> compsize;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]==1) {//new comp discovered
                    compsize[compno]=compdfs(i,j,compno,grid,n);
                    ans=max(ans,compsize[compno]); // max of default comp sz
                    compno++;
                }
            }
        }
        // // printing grid after traversal
        // for(auto r: grid) {
        //     for(auto c: r) {
        //         cout<<c<<" ";
        //     }cout<<endl;
        // }
        // for(auto it: compsize) {
        //     cout<<it.first<<":"<<it.second<<" ";
        // }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]==0) {//check 0->1
                    // cout<<endl<<i<<j<<endl;
                    set<int> comp_nei;//distinct nei comp
                    for(auto dir: dirs) { // check nei comp and size
                        int nx = i+dir[0], ny = j+dir[1];
                        if(0<=nx&&nx<n&&0<=ny&&ny<n&&grid[nx][ny]!=0) {
                            comp_nei.insert(grid[nx][ny]);
                        }
                    }
                    int sz = 0; // 0->1
                    for(auto neicomp: comp_nei) {
                        sz += compsize[neicomp];
                        // cout<<"nei:"<<neicomp<<"sz:"<<sz<<"csz:"<<compsize[neicomp]<<endl;
                    }
                    ans = max(ans,sz+1);
                }
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<vector<int>> g;
    vector<vector<int>> comp;
    vector<vector<bool>> vis;
    map<int,int> compSize;
    int n;
    int compNo;
    
    // return valid neighbour co-ordinates
    vector<pair<int,int>> neighbourPosf(int i, int j) {
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<pair<int,int>> coor;
        for(auto it: dir) {
            int x = i + it.first;
            int y = j + it.second;
            if(x >= 0 && x < n && y >= 0 && y < n) {
                coor.push_back({x,y});
            }
        }
        return coor;
    }

    // Do bfs traversal, marking componentNo - TO-DO
    void bfs(int i, int j) {
        //cout<<"bfs "<<i<<" "<<j<<endl;
        queue<pair<int,int>> qu;
        qu.push({i,j});
        vis[i][j] = true;
        compNo++;
        comp[i][j] = compNo;
        compSize[compNo]++;
        while(!qu.empty()) {
            pair<int,int> coor = qu.front();
            qu.pop();
            vector<pair<int,int>> neigh = neighbourPosf(coor.first,coor.second);
            for(auto it: neigh) {
                if(!vis[it.first][it.second] && g[it.first][it.second] == 1) {
                    qu.push({it.first,it.second});
                    vis[it.first][it.second] = true;
                    comp[it.first][it.second] = compNo;
                    compSize[compNo]++;
                }
            }
        }
        return;
    }

    int largestIsland(vector<vector<int>>& grid) {
        // Initialization
        g = grid;
        n = grid.size();
        compNo = 0;
        vis.resize(n,vector<bool> (n,false));
        comp.resize(n,vector<int> (n,0));
        // traverse, if not visited->traverse marking component no
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && g[i][j] == 1) {
                    bfs(i,j);
                }
            }
        }
        // Update largest Area found till now
        int largestArea = 0;
        // cout<<"compSize:\n";
        for(auto it: compSize) {
            // cout<<it.first<<":"<<it.second<<" ";
            largestArea = max(largestArea,it.second);
        }//cout<<endl;
        // now iterate, if 0 -> check neighbour size and compare and update
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 0) {
                    // find neighbours, and their sizes
                    set<pair<int,int>> neighbour;
                    vector<pair<int,int>> neighbourPos = neighbourPosf(i,j);
                    // cout<<"neighbourPos:\n";
                    for(auto pos: neighbourPos) {
                        int x = pos.first;
                        int y = pos.second;
                        if(g[x][y] != 0) {
                            // cout<<x<<","<<y<<" ";
                            // cout<<"compno:"<<comp[x][y]<<" ";
                            neighbour.insert({comp[x][y],compSize[comp[x][y]]});
                        }//cout<<endl;
                    }
                    // now merge the Areas in neighbour's size and update largest Area
                    // cout<<i<<","<<j<<"\n";
                    int newArea = 0;
                    //cout<<"neighbour Area:\n";
                    for(auto it: neighbour) {
                        //cout<<it.first<<":"<<it.second<<" ";
                        newArea += it.second;
                    }//cout<<endl;
                    newArea += 1; // for the new 0 -> 1
                    //cout<<"newArea:"<<newArea<<endl;
                    largestArea = max(largestArea, newArea);
                }
            }
        }
        return largestArea;
    }
};