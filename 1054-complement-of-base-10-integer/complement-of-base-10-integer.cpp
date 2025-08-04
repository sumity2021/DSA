class Solution {
public:
    int bitwiseComplement(int n) {
        int bits=0;
        int temp=n;
        if(n==0) return 1;
        while(n){
            n>>=1;
            bits++;
        }
        return ((1<<(bits))-1)^temp;
    }
};