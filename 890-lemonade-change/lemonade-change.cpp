class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            m[bills[i]]++;
            if(bills[i]==10 && --m[5]<0) return 0;
            else if(bills[i]==20){
               if(m[5]>=1 && m[10]>=1){
                m[5]--;
                m[10]--;
               }else if(m[5]>=3){
                m[5]-=3;
               }
               else{
                return 0;
               }
            }
        }
        return 1;
    }
};