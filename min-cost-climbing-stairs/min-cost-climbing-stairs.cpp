class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        
        return min(helper(0,cost,n,dp),helper(1,cost,n,dp));
    }
    int helper(int current,vector<int> &cost,int n,vector<int> &dp){
        if(current>=n){
            return 0;
        }
        if(dp[current]!=-1){
            return dp[current];
        }
        int ans=cost[current]+min(helper(current+1,cost,n,dp),helper(current+2,cost,n,dp));
        dp[current]=ans;
        return ans;
    }
};