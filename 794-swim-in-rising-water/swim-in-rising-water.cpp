class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        vector<int>dx={0,0,-1,1};
        vector<int>dy={-1,1,0,0};
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=0;
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            for(int i=0; i<4; i++){
                int nr=node[1]+dx[i];
                int nc=node[2]+dy[i];
                if(nc<n && nc>=0 && nr<n && nr>=0 && dist[nc][nr]>max(node[0],grid[nr][nc])){
                    dist[nc][nr]=max(node[0],grid[nr][nc]);
                    pq.push({max(node[0],grid[nr][nc]),nr,nc});
                }
            }
        }
        return dist[n-1][n-1];
    }
};