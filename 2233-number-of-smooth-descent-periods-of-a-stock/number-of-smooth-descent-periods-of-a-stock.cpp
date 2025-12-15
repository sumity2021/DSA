class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=0;
        int cntr=1;
        int prev=1e9;
        for(int i=0; i<n; i++){
            if(prev-prices[i]==1){
                cntr++;
            }else{
                cntr=1;
            }
            prev=prices[i];
            ans+=cntr;
        }
        return ans;
    }
};