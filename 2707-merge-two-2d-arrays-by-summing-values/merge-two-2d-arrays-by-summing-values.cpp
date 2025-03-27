class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>result;
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i<n && j<m){
            auto num1=nums1[i];
            auto num2=nums2[j];
            if(num1[0]==num2[0]){
                result.push_back({num1[0],num1[1]+num2[1]});
                i++;
                j++;
            }else if(num1[0]>num2[0]){
                result.push_back(num2);
                j++;
            }else{
                result.push_back(num1);
                i++;
            }
        }
        while(i<n){ result.push_back(nums1[i]); i++;}
        while(j<m){result.push_back(nums2[j]); j++;}
        return result;
    }
};