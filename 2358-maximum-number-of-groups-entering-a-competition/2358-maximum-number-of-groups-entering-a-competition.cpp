class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        return (int)( sqrt(0.25 + 2*grades.size()) - 0.5);
    }
};