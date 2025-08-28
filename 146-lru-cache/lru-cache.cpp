class Node{
public:
   int key;
   int val;
   Node*prev;
   Node*next;
   Node(int key , int val){
    this->key=key;
    this->val=val;
   }
};
class LRUCache {
    int cap;
    Node*head;
    Node*tail;
    unordered_map<int, Node*>m;
    void addnode(Node*node){
        head->next->prev=node;
        node->next=head->next;
        head->next=node;
        node->prev=head;
    }
    void deletenode(Node*node){
        node->next->prev=node->prev;
        node->prev->next=node->next;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.count(key)){
            Node*resnode=m[key];
            deletenode(resnode);
            addnode(resnode);
            return resnode->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            Node*resnode=m[key];
            deletenode(resnode);
            m.erase(key);
        }
        if(cap<=m.size()){
            Node*temp=tail->prev;
            tail->prev=temp->prev;
            temp->prev->next=tail;
            m.erase(temp->key);
            delete(temp);
        }
        addnode(new Node(key , value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */