class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lh = height[0];
        int rh = height[n-1];
        int l = 1;
        int r = n-2;
        int water = 0;
        while(l <= r)
        {
            if(height[l] >= lh)
            {
                lh = height[l];
                l++;
            }
            else if(height[r] >= rh)
            {
                rh = height[r];
                r--;
            }
            else if(lh <= rh && height[l] < lh)
            {
                water += lh - height[l];
                l++;
            }
            else
            {
                water += rh - height[r];
                r--;
            }
        
        }
        return water;
    }
};