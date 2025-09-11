class Solution {
public:
    string sortVowels(string s) {
        string vowel="";
        unordered_set<char>v={'a','e','i','o','u','A','E','I','O','U'};
        for(auto it : s){
            if(v.find(it)!=v.end()) vowel+=it;
        }
        sort(vowel.begin(),vowel.end());
        int j=0;
        for(int i=0; i<s.size(); i++){
            if(v.find(s[i])!=v.end()){
                s[i]=vowel[j];
                j++;
            }
        }
        return s;
    }
};