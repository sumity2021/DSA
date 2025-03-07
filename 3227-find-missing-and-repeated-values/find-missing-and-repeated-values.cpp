class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<bool>vis(n*n+1,0);
        int a;
        long long sum=0;
        for(int i=0; i<n*n; i++){
            int row=i/n;
            int col=i%n;
            if(vis[grid[row][col]]){
                a=grid[row][col];
            }
            vis[grid[row][col]]=1;
            sum+=grid[row][col];
        }
        sum-=a;
        int b= abs((n*n)*(n*n+1)/2-sum);
        return {a,b};
    }
};