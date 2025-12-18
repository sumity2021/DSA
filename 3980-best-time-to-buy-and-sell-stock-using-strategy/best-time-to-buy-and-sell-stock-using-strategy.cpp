class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long ans=-1e15;
        int n=prices.size();
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=(prices[i]*strategy[i]);
        }
        ans=max(ans,sum);
        int l=0;
        int m=k/2;
        int r=k;
        for(int i=l; i<m; i++){
            sum-=(prices[i]*strategy[i]);
        }
        for(int i=m; i<r; i++){
            sum-=(prices[i]*strategy[i]);
            sum+=(prices[i]);
        }
        ans=max(ans,sum);
        // cout<<ans<<" ";
        while(r<n){
            sum+=(prices[l]*strategy[l]);
            // cout<<sum<<" ";
            sum-=(prices[m]);
            // cout<<sum<<" ";
            sum-=(prices[r]*strategy[r]);
            sum+=prices[r];
            // cout<<sum<<endl;
            l++;
            m++;
            r++;
            ans=max(ans,sum);
        }
        return ans;

    }
};