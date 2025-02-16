class Solution {
public:
    bool backtrack(vector<int>&vis,vector<int>&ans, int idx, int n){
        while(idx<2*n-1 && ans[idx]!=0){
            idx++;
        }
        if(idx==2*n-1){
            return 1;
        }
        for(int i=n; i>=1; i--){
            if(vis[i]==1)continue;
            int s_idx= (i==1)? idx: idx+i;
            if(s_idx<ans.size() && ans[s_idx]==0){
                ans[idx]=i;
                ans[s_idx]=i;
                vis[i]=1;
                if(backtrack(vis,ans,idx+1,n)){
                    return 1;
                }
                ans[idx]=0;
                ans[s_idx]=0;
                vis[i]=0;
            }
        }
        return 0;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*n-1,0);
        vector<int>vis(n+1,0);
        backtrack(vis,ans,0,n);
        return ans;
    }
};