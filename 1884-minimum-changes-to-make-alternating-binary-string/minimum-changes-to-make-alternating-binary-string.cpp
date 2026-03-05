class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int req_1=0;
        int req_2=1;
        int req_cnt_1=0;
        int req_cnt_2=0;
        for(int i=0; i<n; i++){
            if(s[i]!=req_1+'0'){
                req_cnt_1++;
            }
            if(s[i]!=req_2+'0'){
                req_cnt_2++;
            }
            req_1=!req_1;
            req_2=!req_2;
        }
        return min(req_cnt_1,req_cnt_2);
    }
};