class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> ans;
        map<string,int> mp;
        int n=s.size();
        if(n<10){
            return {};
        }
        int i=0,j=9;
        string temp=s.substr(10);
        mp[temp]+=1;
        while(j<n){
            temp=s.substr(i,10);
            i++;
            j++;
            mp[temp]+=1;
        }
        int counter=0;
        for(auto c:mp){
            if(c.second>1){
                ans.push_back(c.first);
            }
        }
        return ans;
    }
};