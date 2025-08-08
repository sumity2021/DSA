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
        w.push_back(b);
        queue<pair<string,int>>q;
        unordered_set<string>all(w.begin(),w.end());
        q.push({b,1});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            string u=node.first;
            int wt=node.second;
            if(u==e){
                return wt;
            }
            for(int i=0; i<u.size(); i++){
                char orig=u[i];
                for(char ch ='a'; ch<='z'; ch++){
                    if(orig==ch) continue;
                    u[i]=ch;
                    if(all.count(u)){
                        q.push({u,wt+1});
                        all.erase(u);
                    }
                }
                u[i]=orig;
            }
            
        }
        return 0;

    }
};