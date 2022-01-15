class Solution {
public:
   
    int helper(vector<int> &days,vector<int> &costs,int idx,int validity){
    if(idx==days.size()){
        return 0;
        
    }
    
    if(validity<=days[idx]){
        // tkt lena h
        int one=helper(days,costs,idx+1,days[idx]+1)+costs[0];
        int week=helper(days,costs,idx+1,days[idx]+7)+costs[1];
        int month=helper(days,costs,idx+1,days[idx]+30)+costs[2];
        return min(one,min(week,month));
    }else{
        return helper(days,costs,idx+1,validity);
    }
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
  unordered_set<int> travel(begin(days), end(days));
  int dp[366] = {};
  for (int i = 1; i < 366; ++i) {
    if (travel.find(i) == travel.end()) dp[i] = dp[i - 1];
    else dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
  }
  return dp[365];
  //return helper(days,costs,0,0);
}

};