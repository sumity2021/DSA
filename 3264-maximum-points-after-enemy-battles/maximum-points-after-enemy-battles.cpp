class Solution {
public:
    long long maximumPoints(vector<int>& arr, int c) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        long long ans=0;
        if(c<arr[0]) return ans;
        int j=n-1;
        while(j>=0){
            if(c>=arr[0]){
                ans+=c/arr[0];
                c=c%arr[0];
            }
            c+=arr[j];
            j--;
        }
        return ans;
    }
};