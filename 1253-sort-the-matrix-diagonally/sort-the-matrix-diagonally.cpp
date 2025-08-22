class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0; i<m; i++){
            vector<int>temp;
            for(int j=0; j<n && i+j<m; j++){
                temp.push_back(mat[j][i+j]);
            }
            sort(temp.begin(),temp.end());
            for(int j=0; j<n && i+j<m; j++){
                mat[j][i+j]=temp[j];
            }
        }
        for(int i=1; i<n; i++){
            vector<int>temp;
            for(int j=0; j<m && i+j<n; j++){
                temp.push_back(mat[i+j][j]);
            }
            sort(temp.begin(),temp.end());
            for(int j=0; j<m && i+j<n; j++){
                mat[i+j][j]=temp[j];
            }
        }
        return mat;
    }
};