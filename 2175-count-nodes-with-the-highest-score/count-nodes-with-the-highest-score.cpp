class Solution {
    int dfs(vector<vector<int>>&adj,vector<long long>&s, int i){
        long long prod=1,sum=1;
        for(int j : adj[i]){
            int cnt=dfs(adj,s,j);
            sum+=cnt;
            prod*=cnt;
        }
        s[i]=prod*max(1ll,(long long)adj.size()-sum);
        return sum;
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>>adj(n);
        vector<long long>s(n);
        for(int i=1; i<n; i++){
            adj[parents[i]].push_back(i);
        }
        dfs(adj,s,0);
        return count(begin(s), end(s),*max_element(begin(s),end(s)));


    }
};