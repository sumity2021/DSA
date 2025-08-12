struct Node{
    Node*links[26];
    int freq=0;
    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }
    void inc(){
        freq++;
    }
    void put(char ch , Node*node){
        links[ch-'a']=node;
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    int char_freq(){
        return freq;
    }
};
class Trie{
    Node*root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node*node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->inc();
        }
    }
    int prefix(string word){
        Node*node=root;
        int cnt=0;
        for(int i=0; i<word.size(); i++){
            node=node->get(word[i]);
            cnt+=node->char_freq();
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        Trie trie;
        for(int i=0; i<n; i++){
            trie.insert(words[i]);
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            ans.push_back(trie.prefix(words[i]));
        }
        return ans;
    }
};