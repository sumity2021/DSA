class Solution {
public:
    int hammingDistance(int x, int y) {
        if(x<y) return hammingDistance(y,x);
        int ans=0;
        while(x>0){
            int bit_x=(x&1);
            int bit_y=(y&1);
            if((bit_y^bit_x)==1){
                ans++;
            }
            x>>=1;
            y>>=1;
        }
        return ans;
    }
};