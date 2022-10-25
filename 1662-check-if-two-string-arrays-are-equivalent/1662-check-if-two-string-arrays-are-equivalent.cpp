class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string one = "";
        
        for(auto i: word1)
            one += i;
        
        string two = "";
        for(auto i: word2)
            two += i;
        
        return one == two;
    }
};