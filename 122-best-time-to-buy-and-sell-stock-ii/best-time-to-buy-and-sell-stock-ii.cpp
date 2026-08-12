class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0, diff; 
        for(int i=0;i<prices.size()-1;i++){
            diff=prices[i+1]-prices[i];
            if(diff>0) maxProfit+=diff;
        }
        return maxProfit;
    }
};