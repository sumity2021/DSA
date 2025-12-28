class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int i=0;
        int j=m-1;
        int ans=0;
        while(i<n && j>=0){
            if(grid[i][j]<0){
                j--;
                ans+=(n-i);
            }else if(i<n-1 && grid[i+1][j]<0){
                j--;
                ans+=(n-i-1);
            }else{
                i++;
            }
        }
        return ans;
    }
};