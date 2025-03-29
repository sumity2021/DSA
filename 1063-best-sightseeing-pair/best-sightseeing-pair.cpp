class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int left=0;
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans,left+values[i]-i);
            left=max(left,values[i]+i);
        }
        return ans;
    }
};