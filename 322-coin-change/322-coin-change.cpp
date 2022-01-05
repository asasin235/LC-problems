class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;// basically no if no money needed no coins needed.
        for(int i=1;i<=amount;i++){
            for(int j=1;j<=n;j++){
                if(i-coins[j-1]>=0){
                    // take the coin if it gives better ans
                    dp[i]=min(dp[i],dp[i-coins[j-1]]+1);
                }else{
                    dp[i]=dp[i];// dont take the coin
                }
            }
        }
        if(dp[amount]==INT_MAX-1) return -1;
        else return dp[amount];
    }
    
};