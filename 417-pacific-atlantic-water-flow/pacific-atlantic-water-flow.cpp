class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<bool>>vis1(n,vector<bool>(m,0));
        vector<vector<bool>>vis2(n,vector<bool>(m,0));
        queue<vector<int>>q;
        vector<int>dx={0,0,-1,1};
        vector<int>dy={1,-1,0,0};
        for(int i=0; i<n; i++){
            ans[i][0]++;
            q.push({i,0});
            vis1[i][0]=1;
        }
        for(int j=1; j<m; j++){
            ans[0][j]++;
            q.push({0,j});
            vis1[0][j]=1;
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr=node[0]+dx[i];
                int nc=node[1]+dy[i];
                if(nr>=0  && nr<n && nc>=0 && nc<m && !vis1[nr][nc] && heights[node[0]][node[1]]<=heights[nr][nc] ){
                    ans[nr][nc]++;
                    q.push({nr,nc});
                    vis1[nr][nc]=1;
                }
            }
        }
        for(int i=0; i<n; i++){
            ans[i][m-1]++;
            q.push({i,m-1});
            vis2[i][m-1]=1;
        }
        for(int j=0; j<m-1; j++){
            ans[n-1][j]++;
            q.push({n-1,j});
            vis2[n-1][j]=1;
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr=node[0]+dx[i];
                int nc=node[1]+dy[i];
                if(nr>=0  && nr<n && nc>=0 && nc<m && !vis2[nr][nc] && heights[node[0]][node[1]]<=heights[nr][nc] ){
                    ans[nr][nc]++;
                    q.push({nr,nc});
                    vis2[nr][nc]=1;
                }
            }
        }
        vector<vector<int>>res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(ans[i][j]>=2){
                    res.push_back({i,j});
                }
            }
        }
        return res;
        
    }
};