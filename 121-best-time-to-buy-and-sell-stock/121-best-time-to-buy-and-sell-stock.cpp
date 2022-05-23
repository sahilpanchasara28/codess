class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int buy = arr[0], profit = 0;
        for(int i=1; i<arr.size(); i++)
        {
            buy = min(buy, arr[i]);
            profit = max(profit, arr[i]-buy);
        }
        
        return profit;
    }
};