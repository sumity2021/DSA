class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int x=queries.size();
        vector<pair<int,int>>qs;
        for(int i=0; i<x; i++) qs.push_back({queries[i],i}); 
        sort(qs.begin(),qs.end());
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vis[0][0]=1;
        pq.push({grid[0][0],{0,0}});
        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        vector<int>ans(x,0);
        for(auto & [q,idx]:qs){
            while(!pq.empty() && q>pq.top().first){
                auto [val,pos]=pq.top();
                pq.pop();
                cnt++;
                for(auto &it : dir){
                    int nr=pos.first+it[0];
                    int nc=pos.second+it[1];
                    if(nr>=0 && nc>=0 && nc<n && nr<m && !vis[nr][nc]){
                        pq.push({grid[nr][nc],{nr,nc}});
                        vis[nr][nc]=1;
                    }
                }
            }
            ans[idx]=cnt;

        }
        return ans;

    }
};