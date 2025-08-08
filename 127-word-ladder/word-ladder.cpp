class Solution {
public:
    bool check(string s1 , string s2 ){
        int cnt=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]) cnt++;
            if(cnt>1) return 0;
        }
        return cnt==1;

    }
    int ladderLength(string b, string e, vector<string>& w) {
        unordered_map<string, vector<string>>adj;
        w.push_back(b);
        int n=w.size();
        for(int u=0; u<n; u++){
            for(int v=u+1; v<n; v++){
                if(check(w[u],w[v])){
                    adj[w[u]].push_back(w[v]);
                    adj[w[v]].push_back(w[u]);
                }
            }
        }
        queue<pair<string,int>>q;
        unordered_set<string>vis;
        q.push({b,1});
        vis.insert(b);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            string u=node.first;
            int wt=node.second;
            if(u==e){
                return wt;
            }
            for(string v : adj[u]){
                if(!vis.count(v)){
                    q.push({v,wt+1});
                    vis.insert(v);
                }
            }
            
        }
        return 0;

    }
};