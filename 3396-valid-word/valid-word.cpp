class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return 0;
        unordered_set<char>vowels={'a','e','i','o','u','A','E','I','O','U'};
        unordered_set<char>consonants={'b','c','d','f','g','h','j','k','l','m',
        'n','p','q','r','s','t','v','w','x','y','z','B','C','D','F','G','H','J','K','L','M',
        'N','P','Q','R','S','T','V','W','X','Y','Z'};
        unordered_set<char>not_allowed={'@','#','$'};
        bool flag1=0,flag2=0,flag3=1;
        for(auto it : word){
            if(vowels.count(it)) flag1=1;
            if(consonants.count(it)) flag2=1;
            if(not_allowed.count(it)) flag3=0;
        }
        return flag1 && flag2 && flag3;
    }
};