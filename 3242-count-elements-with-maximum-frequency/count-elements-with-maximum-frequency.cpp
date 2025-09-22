class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxfreq=0;
        unordered_map<int,int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i]]>maxfreq){
                maxfreq=m[nums[i]];
            }
        }
        int ans=0;
        for(auto&[key,val] : m){
            if(m[key]==maxfreq){
                ans+=m[key];
            }
        }
        return ans;
    }
};