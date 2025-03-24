class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        int st=meetings[0][0];
        int end=meetings[0][1];
        int ans=st-1;
        for(int i=0; i<n; i++){
            int c=meetings[i][0];
            int d=meetings[i][1];
            if(end<c){
                ans+=(c-end-1);
                st=c;  
                end=d;
            }
            else{
                end=max(end,d);
            }
        }
        return ans+(days-end);
    }
};