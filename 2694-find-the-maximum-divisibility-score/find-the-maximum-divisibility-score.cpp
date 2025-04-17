class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans=-1;
        int max_score=INT_MIN;
        int n=divisors.size();
        int m=nums.size();
        for(int i=0; i<n; i++){
            int score=0;
            for(int j=0; j<m; j++){
                if(nums[j]%divisors[i]==0){
                    score++;
                }
            }
            if(score==max_score){
                ans=min(divisors[i],ans);
            }
            else if(score>max_score){
                max_score=score;
                ans=divisors[i];
            }
        }
        return ans;
    }
};