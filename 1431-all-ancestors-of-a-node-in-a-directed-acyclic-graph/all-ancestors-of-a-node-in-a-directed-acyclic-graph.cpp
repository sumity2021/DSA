class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto it  : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<unordered_set<int>>temp(n);
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v : adj[u]){
                indegree[v]--;
                temp[v].insert(u);
                for(int i : temp[u]){
                    temp[v].insert(i);
                }
                
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        vector<vector<int>>ans(n);
        for(int i=0; i<n; i++ ){
            if(!temp[i].size()) continue;
            for(int node=0; node<n; node++){
                if(temp[i].count(node)){
                    ans[i].push_back(node);
                }
            }
        }
        return ans;
    }
};