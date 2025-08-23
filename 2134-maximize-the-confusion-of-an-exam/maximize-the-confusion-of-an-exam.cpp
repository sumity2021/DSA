class Solution {
public:
    int maxConsecutiveAnswers(string arr, int k) {
        int t=0;
        int f=0;
        int n=arr.size();
        int l=0;
        int mini,maxi;
        int ans=0;
        for(int r=0; r<n; r++){
            if(arr[r]=='T') t++;
            else f++;
            mini=min(t,f);
            maxi=max(t,f);
            while(mini>k){
                if(arr[l]=='T') t--;
                else f--;
                mini=min(t,f);
                maxi=max(t,f);
                l++;
            }
            ans=max(r-l+1,ans);
        }
        return ans;

    }
};