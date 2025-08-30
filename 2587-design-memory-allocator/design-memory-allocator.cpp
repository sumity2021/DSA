class Allocator {
    int* memory;
    int n;
public:
    Allocator(int n) {
        memory = new int[n]; 
        memset(memory,0,n*sizeof(int));
        this->n=n;
    }
    
    int allocate(int size, int mID) {
        int idx=-1;
        for(int i=0; i<n; i++){
            int cnt=0;
            int curr_idx=i;
            while(i<n && memory[i]==0){
                i++;
                cnt++;
            }
            if(size<=cnt) {idx=curr_idx; break;}
        }
        for(int i=idx; i<idx+size && i>=0 ; i++){
            memory[i]=mID;
        }
        return idx;
    }
    
    int freeMemory(int mID) {
        int cnt=0;
        for(int i=0; i<n; i++){
            if(memory[i]==mID) {memory[i]=0; cnt++;}
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */