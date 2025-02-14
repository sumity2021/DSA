class ProductOfNumbers {
    vector<int>arr;
    int zero_idx;
    int size;
public:
    ProductOfNumbers() {
        arr={};
        zero_idx=-1;
        size=0;
    }
    
    void add(int num) {
        if(num==0){
            zero_idx=max(zero_idx,size);
        }
        if(size==0 || arr.back()==0){
            arr.push_back(num);
        }
        else{
            arr.push_back(num*arr.back());
        }
        size++;
    }
    
    int getProduct(int k) {
        int idx=size-k-1;
        if(zero_idx>idx){
            return 0;
        }else if(zero_idx==idx){
            return arr[size-1];
        }
        return arr[size-1]/arr[idx];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */