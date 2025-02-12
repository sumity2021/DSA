class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr=0;
        int ans=0;
        int n=prices.size();
        for(int i=n-1; i>=0; i--){
            curr=max(curr,prices[i]);
            int profit=curr-prices[i];
            if(profit>0){
                ans+=profit;
                curr=prices[i];
            }
        }
        return ans;
    }
};