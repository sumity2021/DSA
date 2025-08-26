class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int maxi=0;
        int max_area=0;
        for(int i=0; i<n; i++){
            int l=dimensions[i][0];
            int r=dimensions[i][1];
            int diagonal_len=l*l + r*r;
            int area=l*r;
            if(maxi<diagonal_len){
                maxi=diagonal_len;
                max_area=area;
            }else if(maxi==diagonal_len){
                max_area=max(max_area,area);
            }
        }
        return max_area;
        
    }
};