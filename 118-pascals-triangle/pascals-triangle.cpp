class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int r=0; r<n; r++){
            vector<int>row(r+1);
            int st=0,end=r;
            row[st]=1,row[end]=1;
            for(int i=st+1; i<end; i++){
                row[i]=ans[r-1][i-1]+ans[r-1][i];
            }
            ans.push_back(row);
        }
        return ans;
    }
};