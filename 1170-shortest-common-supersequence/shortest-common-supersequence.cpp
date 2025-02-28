class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        string scs;
        int i=0,j=0;
        while(j<n && i<m){
            if(text1[i]==text2[j]){
                scs.push_back(text1[i]);
                i++;
                j++;
            }
            else if(dp[i][j+1]>dp[i+1][j]){
                scs.push_back(text2[j]);
                j++;
            }
            else{
                scs.push_back(text1[i]);
                i++;
            }
        }
        while(i<m) scs.push_back(text1[i++]);
        while(j<n) scs.push_back(text2[j++]);
        return scs;
    }
};