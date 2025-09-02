class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](auto a,auto b) {
            return (a[0]==b[0])? a[1]<b[1] : a[0]>b[0];
        });
        int ans=0;
        for(int i=0; i<n; i++){
            int yi=points[i][1],y=INT_MAX;
            for(int j=i+1; j<n; j++){
                int yj=points[j][1];
                if(yj>=yi && y>yj){
                    ans++;
                    y=yj;
                }
            }
        }
        return ans;
    }
};