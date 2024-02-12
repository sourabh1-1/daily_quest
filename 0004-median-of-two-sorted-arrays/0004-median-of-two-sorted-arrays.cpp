class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //brute force
//         double median;
//         int n1=nums1.size();
//         int n2=nums2.size();
        
//         vector<int> merg;
//         for(int i=0;i<n1;i++)
//             merg.push_back(nums1[i]);
//         for(int i=0;i<n2;i++)
//             merg.push_back(nums2[i]);
//         sort(merg.begin(),merg.end());
//         int i=(n1+n2)/2;
//         if((n1+n2)%2==0)
//             median=(merg[i-1]+merg[i])/2.0;
//         else
//             median=merg[i];
//         return median;
        
        //better solution
        int n1=nums1.size(), n2=nums2.size();
        int n=n1+n2;
        int ind2=n/2;
        int ind1=ind2-1;
        int ind1el=-1, ind2el=-1;
        int count=0;
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(count==ind1)
                    ind1el=nums1[i];
                if(count==ind2)
                    ind2el=nums1[i];
                i++;
                count++;
            }
            else{
                if(count==ind1)
                    ind1el=nums2[j];
                if(count==ind2)
                    ind2el=nums2[j];
                j++;
                count++;
            }
        }
        while(i<n1){
            if(count==ind1)
                ind1el=nums1[i];
            if(count==ind2)
                ind2el=nums1[i];
            i++;
            count++;
        }
        while(j<n2){
            if(count==ind1)
                ind1el=nums2[j];
            if(count==ind2)
                ind2el=nums2[j];
            j++;
            count++;
        }
        if(n%2==1)
            return ind2el;
        return (double)(ind1el+ind2el)/2.0;
    }
};