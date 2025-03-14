class Solution {
public:
    bool helper(long long k, vector<int>&candies,int x){
        long long sum=0;
        for( int a : candies){
            sum+=a/x;
        }
        return sum>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long  l=1;
        long long r;
        long long sum=0;
        for( int a : candies){
            sum+=a;
        }
        r=sum/k;
        if(sum<k){
            return 0;
        }
        while(l<=r){
            long long m=(r+l)/2;
            if(helper(k,candies,m)){
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return r;
        
    }
};