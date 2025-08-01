class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,r=n-1,t=0,b=m-1;
        vector<int>ans;
        while(r>=l && b>=t){
            for(int i=l; i<=r; i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            for(int j=t; j<=b; j++){
                ans.push_back(matrix[j][r]);
            }
            r--;
            for(int i=r; i>=l && t<=b; i--){
                ans.push_back(matrix[b][i]);
            }
            b--;
            for(int j=b; j>=t && r>=l; j--){
                ans.push_back(matrix[j][l]);
            }
            l++;
        }
        return ans;
    }
};