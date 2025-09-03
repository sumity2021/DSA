class dsu{
    vector<int>par;
    vector<int>size;
    public:
    dsu(int n){
        par.resize(n,0);
        size.resize(n,0);
        for(int i=0; i<n; i++) par[i]=i;
    }
    int findpar(int u){
        if(u==par[u]) return u;
        return par[u]=findpar(par[u]);
    }
    void join(int u , int v){
        int upu=findpar(u);
        int upv=findpar(v);
        if(upu==upv) return ;
        if(size[upu]>=size[upv]){
            size[upu]+=size[upv];
            par[upv]=upu;
        }
        else{
            size[upv]+=size[upu];
            par[upu]=upv;
        }
    }
    int components(){
        int n=par.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int upu=findpar(i);
            if(i==upu)ans++;
        }
        return ans;
    }
};
class Solution {
    int f(int mid , vector<vector<int>>& edges , int k , int n){
        int m=edges.size();
        dsu dsu(n);
        for(int i=0; i<m; i++){
            if(edges[i][2]<=mid){
                dsu.join(edges[i][0],edges[i][1]);
            }
        }
        int c=dsu.components();
        return c<=k;
    }
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int l=0;
        int r=1e6;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(mid,edges,k,n)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};