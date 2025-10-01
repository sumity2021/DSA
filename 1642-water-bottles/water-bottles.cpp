class Solution {
public:
    int numWaterBottles(int n, int e) {
        int total=0;
        int rem=0;
        while(n){
            total+=n;
            int nb=(n+rem)/e;
            rem=(n+rem)%e;
            n=nb;
        }
        return total;
    }
};