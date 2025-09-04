class Solution {
    bool isvalid(vector<int>&A , vector<int>&B){
        for(int i=0; i<26; i++){
            if(B[i]>A[i]) return 0;
        }
        return 1;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<int>A(26,0);
        for(char ch : p) A[ch-'a']++;
        int l=0;
        vector<int>B(26,0);
        vector<int>ans;
        for(int r=0; r<n; r++){
            B[s[r]-'a']++;
            while(!isvalid(A,B)){
                B[s[l]-'a']--;
                l++;
            }
            if(A==B) ans.push_back(l);

        }
        return ans;

    }
};