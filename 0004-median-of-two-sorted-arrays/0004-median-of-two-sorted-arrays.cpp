class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        int n1=nums1.size();
        int n2=nums2.size();
        
        vector<int> merg;
        for(int i=0;i<n1;i++)
            merg.push_back(nums1[i]);
        for(int i=0;i<n2;i++)
            merg.push_back(nums2[i]);
        sort(merg.begin(),merg.end());
        int i=(n1+n2)/2;
        if((n1+n2)%2==0)
            median=(merg[i-1]+merg[i])/2.0;
        else
            median=merg[i];
        return median;
    }
};