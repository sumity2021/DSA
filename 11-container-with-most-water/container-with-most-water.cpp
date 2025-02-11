class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<j){
            int curr=(j-i)*min(height[i],height[j]);
            ans=max(ans,curr);
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};