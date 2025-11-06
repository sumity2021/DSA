class Solution {
    void dfs(int node , int grid , vector<vector<int>>&adj , vector<int>&grids){
        grids[node]=grid;
        for(auto it : adj[node]){
            if(grids[it]==-1){
                dfs(it,grid,adj,grids);
            }
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>>adj(c+1);
        for(auto e : connections){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>grids(c+1,-1);
        int grid=0;
        for(int i=1; i<=c; i++){
            if(grids[i]==-1){
                dfs(i,grid,adj,grids);
                grid++;
            }
        }
        vector<set<int>>op_grids(grid);
        for(int i=1; i<=c; i++){
            op_grids[grids[i]].insert(i);
        }
        vector<int>ans;
        for(auto q : queries){
            if(q[0]==2 ){
                if(op_grids[grids[q[1]]].count(q[1]))op_grids[grids[q[1]]].erase(q[1]);
            }else{
                if(op_grids[grids[q[1]]].empty()){
                    ans.push_back(-1);
                }
                else if(op_grids[grids[q[1]]].count(q[1])){
                    ans.push_back(q[1]);
                }else{
                    auto it = op_grids[grids[q[1]]].begin();
                    ans.push_back(*it);
                }
            }
        }
        return ans;
    }
};