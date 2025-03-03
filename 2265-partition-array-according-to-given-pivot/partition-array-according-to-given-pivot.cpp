class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n,0);
        int st=0,end=n-1;
        for(int i=0; i<n; i++){
            if(nums[i]<pivot){
                ans[st]=nums[i];
                st++;
            }
            else if(nums[i]>pivot){
                ans[end]=nums[i];
                end--;
            }
        }
        for(int i =st; i<=end; i++){
            ans[i]=pivot;
        }
        st=++end;
        end=n-1;
        while(st<end){
            swap(ans[st],ans[end]);
            st++;
            end--;
        }
        return ans;
    }
};