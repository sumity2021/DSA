class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int ans=0;
        sort(piles.begin(),piles.end());
        for(int i=n/3; i<n; i+=2){
            ans+=piles[i];
        }
        return ans;
    }
};