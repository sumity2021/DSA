class Dsu{
    vector<int>par;
    vector<int>size;
public:
    Dsu(int n){
        size.resize(n,1);
        for(int i=0; i<n; i++) par.push_back(i);
    }
    int find_par(int u){
        if(u==par[u]) return u;
        return par[u]=find_par(par[u]);
    }
    void union_size(int u , int v){
        int upu=find_par(u);
        int upv=find_par(v);
        if(upu == upv) return;
        else if(size[upu]>=size[upv]){
            par[upv]=upu;
            size[upu]+=size[upv];
        }else{
            par[upu]=upv;
            size[upv]+=size[upu];
        }
    }
    int components(int n){
        int cnt=0;
        for(int i=0; i<n; i++){
            if(i==find_par(i)) cnt++;
        }
        return cnt;
    }
    
};

class Solution {
    bool check(string s1 , string s2){
        int diff=0;
        vector<int>pos;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                diff++;
                pos.push_back(i);
                if(diff>2) return 0;
            }
        }
        return diff==0 || (s1[pos[0]]==s2[pos[1]] && s1[pos[1]]==s2[pos[0]]);
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        Dsu dsu(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(check(strs[i],strs[j])) dsu.union_size(i,j);
            }
        }
        return dsu.components(n);
    }
};