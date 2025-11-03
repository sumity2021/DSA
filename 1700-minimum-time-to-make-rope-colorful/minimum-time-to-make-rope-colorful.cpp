class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;
        for(int i=0; i<n-1; i++){
            int idx=i;
            while(i<n-1 && colors[i]==colors[i+1]){
                i++;
            }
            sort(neededTime.begin()+idx,neededTime.begin()+i+1);
            for(int j=idx; j<i; j++){
                ans+=neededTime[j];
                // cout<<ans<<" ";
            }
        }
        return ans;
    }
};