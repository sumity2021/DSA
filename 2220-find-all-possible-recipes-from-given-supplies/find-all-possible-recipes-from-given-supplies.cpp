class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int i=0;
        unordered_map<string,int>m;
        for(auto it : recipes){
            if(!m.count(it)){ m[it]=i; i++;}
        }
        for(auto it : supplies){
            if(!m.count(it)){ m[it]=i; i++;}
        }
        vector<int>indegree(i,0);
        vector<vector<int>>adj(i);
        for(int j=0; j<recipes.size(); j++){
            int v=m[recipes[j]];
            for(auto it : ingredients[j]){
                if(!m.count(it)){
                    indegree[v]++;
                    continue;
                }
                int u=m[it]; 
                adj[u].push_back(v);
                indegree[v]++;
            }
        }
        queue<int>q;
        for(auto it : supplies){
            int u=m[it];
            q.push(u);
        }
        vector<string>ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    ans.push_back(recipes[v]);
                }
            }
        }
        return ans;


    }
};