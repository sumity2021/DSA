class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum= accumulate(cardPoints.begin(),cardPoints.end(),0);
        int minsum=0;
        int l=0;
        k=n-k;
        int remsum=INT_MAX;
        for(int i=0; i<n; i++){
            minsum+=cardPoints[i];
            if(i-l+1>k){
                minsum-=cardPoints[l++];
            }
            if(i-l+1==k){
                remsum=min(minsum,remsum);
            }
        }
        return sum-remsum;
    }
};