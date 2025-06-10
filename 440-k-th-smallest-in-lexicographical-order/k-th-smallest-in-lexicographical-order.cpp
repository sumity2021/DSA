class Solution {
    #define ll long long 
    int f(int n , ll prefix1, ll prefix2 ){
        int steps=0;
        while(prefix1<=n){
            steps+=min((ll)(n+1), prefix2)-prefix1;
            prefix1*=10;
            prefix2*=10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k){
            int steps=f(n,curr,curr+1);
            if(steps<=k){
                curr++;
                k-=steps;
            }else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};