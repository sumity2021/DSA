class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int wt=node.first;
            int row=node.second.first;
            int col=node.second.second;
            for(int i=0; i<4; i++){
                int newrow=row+dir[i].first;
                int newcol=col+dir[i].second;
                if(newrow<n && newrow>=0 && newcol<m && newcol>=0 && dis[newrow][newcol]>dis[row][col]+wt){
                    dis[newrow][newcol]=dis[row][col]+wt;
                    pq.push({grid[newrow][newcol],{newrow,newcol}});
                }

            }
        }
        return dis[n-1][m-1];
    }
};