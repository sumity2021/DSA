class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>dp(n);
        dp=matrix[0];
        for(int i=1; i<n; i++){
            vector<int>temp(n);
            for(int j=0; j<n; j++){
                int up_left=INT_MAX , up=dp[j] , up_right=INT_MAX; 
                if(j!=0) up_left=dp[j-1];
                if(j!=n-1) up_right=dp[j+1];
                temp[j]=matrix[i][j]+min({up_left,up,up_right});
            }
            dp=temp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};