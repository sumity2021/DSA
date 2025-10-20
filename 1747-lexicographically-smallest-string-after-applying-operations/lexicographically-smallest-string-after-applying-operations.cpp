class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n=s.size();
        unordered_set<string>vis;
        queue<string>q;
        string ans=s;
        q.push(s);
        while(!q.empty()){
            string node=q.front();
            ans=min(ans,node);
            q.pop();
            string rot=node;
            rotate(rot.begin(),rot.begin()+b,rot.end());
            if(!vis.count(rot)){
                q.push(rot);
                vis.insert(rot);
            }
            string add=node;
            for(int i=0; i<n; i++){
                if(i&1){
                    add[i]=((add[i]-'0')+a)%10 + '0';
                }
            }
            if(!vis.count(add)){
                q.push(add);
                vis.insert(add);
            }
        }
        return ans;
    }
};