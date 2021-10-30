class Solution {
public:
  int find_max(vector<int>&segtree,int start,int last,int node,int lnode,int rnode)
    {
        // cout<<node<<" "<<lnode<<" "<<rnode<<endl;
        if(start<=lnode && rnode<=last)
            return segtree[node];
        else if(lnode>last || rnode<start)
            return INT_MIN;
        else
        {
            return max(find_max(segtree,start,last,node*2,lnode,(lnode+rnode)/2),find_max(segtree,start,last,node*2+1,(lnode+rnode)/2+1,rnode));
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int s=1;
        while(s<n)
        {
            s=s*2;
        }
        vector<int>segtree(2*s);
        for(int i=0;i<s-n;i++)
            nums.push_back(0);
        int j=2*s-1;
        for(int i=s-1;i>=0;i--)
        {
            segtree[j]=nums[i];
            j--;
        }
        // cout<<s<<endl;
        //setting up seg tree to find max
        int index=j;
        // cout<<index<<endl;
        for(int i=index;i>=1;i--)
        {
            
            segtree[i]=max(segtree[2*i],segtree[2*i+1]);
        }
        // cout<<"okay"<<endl;
        vector<int>ans;
        for(int i=0;i<=n-k;i++)
        {
            // cout<<"sent "<<i+1<<" "<<i+k<<endl;
            ans.push_back(find_max(segtree,i+1,i+k,1,1,s));
        }
        return ans;
    }
};