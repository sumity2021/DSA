class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        vector<int>temp;
        unordered_map<int,int>m;
        for(int i=0; i<n; i++){
            m[target[i]]=i;
        }
        for(int i=0; i<arr.size(); i++){
            if(m.count(arr[i])){
                temp.push_back(m[arr[i]]);
            }
        }

        vector<int>lis;
        for(int i=0; i<temp.size(); i++){
            if(lis.size()==0 || lis.back()<temp[i]){
                lis.push_back(temp[i]);
            }
            else{
                lis[lower_bound(lis.begin(),lis.end(),temp[i])-lis.begin()]=temp[i];
            }
        }
        return n-lis.size();
    }
};