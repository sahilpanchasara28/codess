class FindSumPairs {
public:
    vector<int> num1;
    vector<int> num2;
    unordered_map<int, int> m2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1 = nums1;
        num2 = nums2;
        
        for(auto i: nums2)
            m2[i]++;
    }
    
    void add(int index, int val) {
        m2[num2[index]]--;
        num2[index] += val;
        m2[num2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(int i=0; i<num1.size(); i++)
        {
            int diff = tot-num1[i];
            if(m2.find(diff) != m2.end())
                c += m2[diff];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */