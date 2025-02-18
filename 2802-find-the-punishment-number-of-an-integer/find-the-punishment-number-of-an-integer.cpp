class Solution {
public:
    bool f(int idx, string s , int target){
        if(idx==s.size() && target==0){
            return 1;
        }
        int sum=0;
        for(int i=idx; i<s.size(); i++){
            int num=stoi(s.substr(idx,i-idx+1));
            sum+=num;
            if(f(i+1,s,target-sum)) return 1;
            sum-=num;
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1; i<=n; i++){
            int num=i*i;
            string check=to_string(num);
            ans+= (f(0,check,i))? i*i:0;
        }
        return ans;
    }
};