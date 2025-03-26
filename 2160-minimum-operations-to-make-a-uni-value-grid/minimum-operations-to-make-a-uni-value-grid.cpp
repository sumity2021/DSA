class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>arr(n*m,0);
        for(int i=0; i<m*n; i++){
            int row=i/m;
            int col=i%m;
            arr[i]=grid[row][col];
        }
        sort(arr.begin(),arr.end());
        int mid=(n*m)/2;
        int mid_ele=arr[mid];
        int ans=0;
        for(int i=0; i<m*n; i++){
            int diff=abs(mid_ele-arr[i]);
            if(diff%x!=0) return -1;
            ans+=(diff/x);
        }
        return ans;
    }
};