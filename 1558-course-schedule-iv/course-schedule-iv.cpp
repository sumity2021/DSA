class Solution {
    void add(vector<unordered_set<int>>&d, int u , int v){
        for(auto it: d[u]){
            d[v].insert(it);
        }
        d[v].insert(u);
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& qs) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        vector<unordered_set<int>>d(n);
        for(int i=0; i<p.size(); i++){
            auto node=p[i];
            int u=node[0];
            int v=node[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(!indegree[i])q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                add(d,node,it);
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<bool>ans;
        for(int i=0; i<qs.size(); i++){
            auto query=qs[i];
            int u=query[0];
            int v=query[1];
            if(d[v].count(u)) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};