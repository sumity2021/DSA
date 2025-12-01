class Solution {
    bool f(vector<int>&arr, int k , int h){
        long long total_time=0;
        for(int x : arr){
            total_time+=ceil((double)x/k);
        }
        return total_time<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=1e9;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(piles,mid,h)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};