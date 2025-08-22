class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=1; i<m; i++){
            vector<int>temp;
            for(int j=0; j<n && i+j<m; j++){
                temp.push_back(mat[j][i+j]);
            }
            sort(temp.begin(),temp.end());
            for(int j=0; j<n && i+j<m; j++){
                mat[j][i+j]=temp[j];
            }
        }
        for(int i=0; i<n; i++){
            vector<int>temp;
            for(int j=0; j<m && i+j<n; j++){
                temp.push_back(mat[i+j][j]);
            }
            sort(temp.begin(),temp.end(),greater<int>());
            for(int j=0; j<m && i+j<n; j++){
                mat[i+j][j]=temp[j];
            }
        }
        return mat;
    }
};