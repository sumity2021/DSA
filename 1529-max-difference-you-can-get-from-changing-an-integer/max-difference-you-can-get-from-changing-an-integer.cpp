class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        int n=s.size();
        int a=0;
        int prod=1;
        for(int i=0; i<n; i++){
            if(s[i]=='1' || s[i]=='0') continue;
            char ch=s[i];
            if(i==0){
                for(int i=n-1; i>=0; i--){
                    if(s[i]==ch){
                        a+=prod;
                    }else{
                        a+=(s[i]-'0')*prod;
                    }
                    prod*=10;
                }
            }else{
                for(int i=n-1; i>=0; i--){
                    if(s[i]==ch){
                        a+=0;
                    }else{
                        a+=(s[i]-'0')*prod;
                    }
                    prod*=10;
                }
            }
            break;
        }

        int b=0;
        prod=1;
        for(int i=0; i<n; i++){
            if(s[i]=='9') continue;
            char ch=s[i];
            for(int i=n-1; i>=0; i--){
                if(s[i]==ch){
                    b+=9*prod;
                }else{
                    b+=(s[i]-'0')*prod;
                }
                prod*=10;
            }
            break;
        }
        if(a==0) a=num;
        if(b==0) b=num;
        return b-a;
    }
};