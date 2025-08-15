class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>arr;
        int j=0;
        for(int i=0; i<n; i++){
            arr.push_back(startTime[i]-j);
            j=endTime[i];
        }
        arr.push_back(eventTime-j);

        k=k+1;
        int l=0;
        int sum=0;
        int ans=0;
        for(int r=0; r<arr.size(); r++){
            sum+=arr[r];
            while(r-l+1>k){
                sum-=arr[l];
                l++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};