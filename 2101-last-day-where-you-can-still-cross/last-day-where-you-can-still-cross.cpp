class Solution {
bool bfs(int mid , vector<vector<int>>grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    vector<int>dx={0,0,-1,1};
    vector<int>dy={-1,1,0,0};
    queue<vector<int>>q;
    for(int i=0; i<m; i++){
        if(grid[0][i]>=mid){
            q.push({0,i});
            vis[0][i]=1;
        }
    }
    while(!q.empty()){
        auto node =q.front();
        q.pop();
        int u=node[0];
        int v=node[1];
        if(u==n-1){
            return 1;
        }
        for(int i=0; i<4; i++){
            int nu=u+dx[i];
            int nv=v+dy[i];
            if(nu<n && nv<m && nu>=0 && nv>=0 && !vis[nu][nv] && grid[nu][nv]>=mid){
                q.push({nu,nv});
                vis[nu][nv]=1;
            }
        }
    }
    return 0;
}
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>>grid(row,vector<int>(col,0));
        int cntr=1;
        for(auto it : cells){
            int u=it[0];
            int v=it[1];
            grid[u-1][v-1]=cntr;
            cntr++;
        }
        int st=1;
        int end=row*col;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(bfs(mid , grid)){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return end-1;
    }
};