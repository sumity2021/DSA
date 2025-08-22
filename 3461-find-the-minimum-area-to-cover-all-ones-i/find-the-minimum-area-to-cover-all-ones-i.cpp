class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int r1=n,r2=-1,c1=m,c2=-1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    r1=min(r1,i);
                    r2=max(r2,i);
                    c1=min(c1,j);
                    c2=max(c2,j);
                }
            }
        }


        return (r2-r1+1)*(c2-c1+1);


        
    }
};