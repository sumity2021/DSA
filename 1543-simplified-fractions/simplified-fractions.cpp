class Solution {
    int gcd(int a , int b){
        while(b){
            int rem=a%b;
            a=b;
            b=rem;
        }
        return a;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        for(int i=2; i<=n; i++){
            for(int j=1; j<i; j++){
                if(gcd(i,j)!=1) continue;
                string ele=to_string(j)+"/"+to_string(i);
                ans.push_back(ele);
            }
        }
        return ans;
    }
};