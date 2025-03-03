class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int i=digits.size()-1;
        while(carry && i>=0){
            digits[i]=(digits[i]+carry)%10;
            if(digits[i]) carry=0;
            i--;
        }
        if(carry){
            vector<int>ans;
            ans.push_back(1);
            for(auto it : digits) ans.push_back(it);
            return ans;
        }
        return digits;
    }
};