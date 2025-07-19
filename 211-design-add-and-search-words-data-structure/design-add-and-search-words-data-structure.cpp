struct Node{
    Node*links[26];
    bool flag=false;
    Node*getkey(char ch){
        return links[ch-'a'];
    }
    void putkey(char ch , Node*node){
        links[ch-'a']=node;
    }
    bool containskey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void setend(){
        flag=true;
    }
    bool isend(){
        return flag;
    }
};
class WordDictionary {
    Node*root;
    bool helper(Node*node, string&word,int idx ){
        if(idx==word.size()){
            return node->isend();
        }
        if(word[idx]=='.'){
            for(char ch='a'; ch<='z'; ch++){
                if(node->containskey(ch)){
                    if(helper(node->getkey(ch),word,idx+1)){
                        return true;
                    }
                }
            }
            return false;
        }
        else{
            if(!node->containskey(word[idx])) return false;
            return helper(node->getkey(word[idx]),word,idx+1);
        }
    }
public:
    WordDictionary() {
        root= new Node();
    }
    
    void addWord(string word) {
        Node*node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                node->putkey(word[i],new Node());
            }
            node=node->getkey(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
        return helper(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */