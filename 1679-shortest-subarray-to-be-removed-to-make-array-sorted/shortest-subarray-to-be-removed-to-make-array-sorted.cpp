class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int r=n-1;
        int l=0;
        while(l<n-1 && arr[l]<=arr[l+1]) l++;
        while(r>0 && arr[r]>=arr[r-1]) r--;
        if(l>=r) return 0;
        int ans=min(n-l-1,r);
        for(int i=0; i<=l && r<n; i++){
            if(arr[i]<=arr[r]){
                ans=min(ans,r-i-1);
            }else{
                r++;
            }
        }
        return ans;
    }
};