class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxArea=0;
        int i=0;
        int j=n-1;
        // area=l*b
        while(i<j){
            int area=(j-i)*(min(height[i],height[j]));
             maxArea=max(maxArea,area);
            if(height[i]>height[j]){
                j--;
            }else {
                i++;
            }
            
        }
        return maxArea;
    }
};