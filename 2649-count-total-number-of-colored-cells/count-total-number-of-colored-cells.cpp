class Solution {
public:
    long long coloredCells(int n) {
        long long cnt=1;
        for(long long i=0; i<n; i++){
            cnt+=4*i;
        }
        return cnt;
    }
};