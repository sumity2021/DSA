class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int maxi=INT_MIN;
        int sum=0;
        for(int i=n-k; i<n; i++){
            for(int j=i; j>=0; j-=k){
                sum+=energy[j];
                maxi=max(sum,maxi);
            }
            sum=0;
        }
        return maxi;
    }
};