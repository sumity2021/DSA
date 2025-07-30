class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        vector<vector<int>>freq_all(n,vector<int>(26,0));
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i=0; i<n; i++){
            freq_all[i][colors[i]-'a']++;
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int ans=0;
        int topo_size=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo_size++;
            for(int adjnode: adj[node]){
                for(int i=0; i<26; i++){
                    int add=(colors[adjnode]-'a'==i)? 1: 0;
                    freq_all[adjnode][i]=max(freq_all[adjnode][i],freq_all[node][i]+add);
                }
                indegree[adjnode]--;
                if(!indegree[adjnode]) q.push(adjnode);
            }
            for(int i=0; i<26; i++){
                ans=max(ans,freq_all[node][i]);
            }
        }
        return (topo_size!=n)? -1 : ans;

        
    }
};