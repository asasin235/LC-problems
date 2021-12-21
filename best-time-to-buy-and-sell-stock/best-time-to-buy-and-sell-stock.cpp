class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        int buy_val=prices[0];
        for(int i=1;i<n;i++){
             ans=max(ans,prices[i]-buy_val);
            if(buy_val>prices[i])
                buy_val=prices[i];
           
        }
        return ans;
    }
};