class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>temp;
        int n=intervals.size();
        for(int i=0; i<n; i++){
            if(intervals[i][0]>newInterval[0]){
                temp.push_back(newInterval);
                newInterval[0]=INT_MAX;
            }
            temp.push_back(intervals[i]);
        }
        if(temp.size()==n) temp.push_back(newInterval);
        vector<vector<int>>ans;
        ans.push_back(temp[0]);
        for(int i=1; i<=n; i++){
            if(ans.back()[1]>=temp[i][0]){
                ans.back()[1]=max(ans.back()[1],temp[i][1]);
                continue;
            }
            ans.push_back(temp[i]);

        }
        return ans;
    }
};