struct Node{
    Node*links[26];
    bool flag=false;

    bool containskey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node*get(char ch){
        return links[ch-'a'];
    }

    void put(char ch , Node*node){
        links[ch-'a']=node;
    }

    void setend(){
        flag=true;
    }

    bool isend(){
        return flag;
    }
};
class Trie{
    private: Node*root;
    public:

    Trie(){
        root= new Node();
    }
    void insert(string word) {
        Node*node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->setend();
    }

    bool search(string word) {
        Node*node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->isend();
    }

    bool startsWith(string word) {
        Node*node=root;
        for(int i=0; i<word.size(); i++){
            if(!node->containskey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */