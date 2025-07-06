class FindSumPairs {
    vector<int>nums2;
    vector<int>nums1;
    unordered_map<int,int>m;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums2=nums2;
        this->nums1=nums1;
        for(int i=0; i<nums2.size(); i++){
            m[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        m[nums2[index]]--;
        nums2[index]+=val;
        m[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0; i<nums1.size(); i++){
            int ele=tot-nums1[i];
            ans+=m[ele];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */