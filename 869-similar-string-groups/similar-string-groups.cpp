class Dsu{
    vector<int>par;
    vector<int>ele;
    int sz;
public:
    Dsu(int n){
        sz=n;
        ele.resize(n,1);
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
        else if(ele[upu]>=ele[upv]){
            par[upv]=upu;
            ele[upu]+=ele[upv];
        }else{
            par[upu]=upv;
            ele[upv]+=ele[upu];
        }
        sz--;
    }
    int size(){
        return sz;
    }
    
};

class Solution {
    bool check(string s1 , string s2){
        int diff=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                diff++;
                if(diff>2) return 0;
            }
        }
        return 1;
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
        return dsu.size();
    }
};