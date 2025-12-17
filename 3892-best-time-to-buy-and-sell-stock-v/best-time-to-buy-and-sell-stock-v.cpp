class Solution {
    long long dp[1001][501][3];
    long long f(int i , int k , int scenario , vector<int>&prices){
        if(i>=prices.size()){
            return (scenario==0) ? 0 : -1e15;
        }
        if(dp[i][k][scenario]!=-1){
            return dp[i][k][scenario];
        }
        long long notake=f(i+1,k,scenario,prices);
        long long take=0;
        if(k>0){
            if(scenario==0){
                take=max(f(i+1,k,1,prices)-prices[i],f(i+1,k,2,prices)+prices[i]);

            }else if(scenario==1){
                take=f(i+1,k-1,0,prices)+prices[i];
            }else{
                take=f(i+1,k-1,0,prices)-prices[i];
            }
        }
        return dp[i][k][scenario]=max(take,notake);
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, -1, sizeof(dp));
        return f(0,k,0,prices);
    }
};