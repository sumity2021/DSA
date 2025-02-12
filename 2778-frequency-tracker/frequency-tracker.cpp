class FrequencyTracker {
public:
    unordered_map<int,int>num;
    unordered_map<int,int>freq;
    FrequencyTracker() {
        num={};
        freq={};
    }
    
    void add(int number) {
        if(num[number]>0){
            freq[num[number]]--;
        }
        num[number]++;
        freq[num[number]]++;
    }
    
    void deleteOne(int number) {
        if(num[number]<=0){
            return;
        }
        freq[num[number]]--;
        num[number]--;
        freq[num[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        return freq[frequency]>0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */