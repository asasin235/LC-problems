class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        int k=0;
        while(k<nums.size() and nums[k]<0 ){
            nums[k]=0;
            k++;
        }
int mex = 1;
for (auto& e:nums) {
	if (e == mex) {
		mex++;
	}
}
  return mex;  
    }
};