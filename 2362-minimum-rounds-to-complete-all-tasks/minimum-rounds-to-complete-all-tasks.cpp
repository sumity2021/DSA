class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>m;
        for(auto it : tasks){
            m[it]++;
        }
        int ans=0;
        for(auto &[key,val] : m){
            if(val==1){
                return -1;
            }else{
                if(val==2) ans++;
                else if(val==3) ans++;
                else{
                    if(val%3==0){
                        ans+=val/3;
                    }
                    else{
                        ans+=val/3+1;
                    }
                }
            }
        }
        return ans;
    }
};