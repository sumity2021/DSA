class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        deque<pair<int,int>>dq;
        dq.push_front({0,0});
        while(!dq.empty()){
            auto node=dq.front();
            dq.pop_front();
            int row=node.first;
            int col=node.second;
            for(int i=0; i<4; i++){
                int newrow=row+dir[i].first;
                int newcol=col+dir[i].second;
                if(newrow<n && newrow>=0 && newcol<m && newcol>=0 && dis[newrow][newcol]>dis[row][col]+grid[row][col]){
                    dis[newrow][newcol]=dis[row][col]+grid[row][col];
                    if(grid[row][col]==1){
                        dq.push_back({newrow,newcol});
                    }else{
                        dq.push_front({newrow,newcol});
                    }
                }

            }
        }
        return dis[n-1][m-1];
    }
};