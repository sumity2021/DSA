class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i=0;
        int j=0;
        int n=word1.size();
        int m=word2.size();
        string merge;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                if(word1.substr(i,n-i+1)>word2.substr(j,m-j+1)){
                    merge.push_back(word1[i]);
                    i++;
                }else{
                    merge.push_back(word2[j]);
                    j++;
                }
            }
            else if(word1[i]>word2[j]){
                merge.push_back(word1[i]);
                i++;
            }else{
                merge.push_back(word2[j]);
                j++;
            }
        }
        while(i<n) merge.push_back(word1[i++]);
        while(j<m) merge.push_back(word2[j++]);
        return merge; 
    }
};