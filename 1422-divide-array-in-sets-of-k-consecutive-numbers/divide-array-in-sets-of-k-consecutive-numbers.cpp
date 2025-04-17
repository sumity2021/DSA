class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int>m(nums.begin(),nums.end());
        while(!m.empty()){
            int start=*m.begin();
            for(int i=0; i<k; i++){
                auto it=m.find(start+i);
                if(it==m.end()) return 0;
                m.erase(it);

            }
        }
        return 1;
        
    }
};