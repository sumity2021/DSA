class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int odd=0;
        int even=0;
        int alt=0;
        int flag=-1;
        for(int i=0; i<n; i++){
            if(nums[i] &1){
                odd++;
                if(flag!=0){ alt++; flag=0;}
            }
            else{
                even++;
                if(flag!=1){alt++; flag=1;}
            }
        }
        return max({alt,odd,even});
    }
};