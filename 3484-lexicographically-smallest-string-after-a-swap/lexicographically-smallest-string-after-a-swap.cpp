class Solution {
public:
    string getSmallestString(string s) {
        int n=s.size();
        for(int i=0; i<n-1; i++){
            int num1=s[i]-'0';
            int num2=s[i+1]-'0';
            bool parity1=num1 & 1;
            bool parity2=num2 & 1;
            if((parity1 ^ parity2)==0 && num1>num2){
                swap(s[i],s[i+1]);
                break;
            }
        }
        return s;
    }
};