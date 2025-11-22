class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n=hamsters.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(hamsters[i]=='H'){
                char left='0';
                char right='0';
                if(i>0) left=hamsters[i-1];
                if(i<n-1) right=hamsters[i+1];
                if((left=='H' || left=='0') && (right=='H' || right=='0'))return -1;
                if(left!='F'){
                    if(right=='.'){
                        hamsters[i+1]='F';
                    }else{
                        hamsters[i-1]='F';
                    }
                    ans++;
                }

            }

        }
        return ans;
    }
};