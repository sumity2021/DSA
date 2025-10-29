class Solution {

    bool dfs(int node , vector<vector<int>>& graph , bool color ,vector<int>&colors){
        colors[node]=color;
        for(auto it : graph[node] ){
            if(colors[it]==-1){
                if(!dfs(it,graph,!color,colors)) return 0;
            }
            else if(colors[it]==color){
                return 0;
            }
        }
        return 1;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colors(n,-1);
        for(int i=0; i<n; i++){
            if(colors[i]==-1){
                if(!dfs(i,graph,0,colors)) return 0;
            }
        }
        return 1;
    }
};