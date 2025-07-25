class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1) return 0;
        int ans=0;
        sort(intervals.begin(),intervals.end());
        int prev=intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0]<prev){
                ans++;
                prev=min(intervals[i][1],prev);
            }else{
                prev=intervals[i][1];
            }
        }
        return ans;
    }
};