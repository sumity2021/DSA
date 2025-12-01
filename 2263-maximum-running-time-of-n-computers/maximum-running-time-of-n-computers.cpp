class Solution {
    bool f(long long mid , vector<int>&arr, int n){
        long long total=0;
        for(int x : arr){
            total+=min(1LL*x,mid);
        }
        return total>=mid*n;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=0;
        long long r=1e14;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(f(mid,batteries,n)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return r;
    }
};