class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<i+1; j++){
                int left=INT_MAX, right=INT_MAX;
                if(j-1>=0) left=triangle[i-1][j-1];
                if(j<i) right=triangle[i-1][j];
                triangle[i][j]+=min(left,right);
            }
        }
        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};