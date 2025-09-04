class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n,1e6);
        vector<vector<vector<int>>>adj(n);
        for( auto it : times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u-1].push_back({v-1,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty()){
            auto node=pq.top();
            int u=node.second;
            pq.pop();
            for(auto it : adj[u]){
                int v=it[0];
                int wt=it[1];
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({wt,v});
                }
            }
        }
        int ans=*max_element(dist.begin(),dist.end());
        return (ans==1e6)? -1 : ans;
    }
};