class Solution {
public:
    int recFun(vector<int>& heights,int ind)
    {
        if(ind==0)
        {
            return 0;
        }
        int left=recFun(heights,ind-1)+(abs(heights[ind]-heights[ind-1]));
        int right=INT_MAX;
        if(ind>1)
        {
            right=recFun(heights,ind-2)+(abs(heights[ind]-heights[ind-2]));   
        }
        return min(left,right);
    }

    int frogJump(vector<int>& heights) {
        return recFun(heights,heights.size());
    }
};