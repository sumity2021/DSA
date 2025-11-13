class Solution {
    int f(int i , int j , string text1 ,string text2){
        if(i>=text1.size() || j>=text2.size()) return 0;
        if(text1[i]==text2[j]){
            return 1+f(i+1,j+1,text1,text2);
        }
        return max(f(i+1,j,text1,text2),f(i,j+1,text1,text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};