class Solution {
public:
    bool check(int n1, int n2){
        string num1=to_string(n1);
        string num2=to_string(n2);
        sort(num1.begin(),num1.end());
        sort(num2.begin(),num2.end());
        return num1==num2;
    }
    bool reorderedPowerOf2(int n) {
        for(int i=0; i<32; i++){
            if(check(n,(1<<i))) return 1;
        }
        return 0;
    }
};