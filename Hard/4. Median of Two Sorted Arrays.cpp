//Brute force is very very easy
//O(m+n)log(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){
            merged.push_back(nums1[i]);
        }
        for(int j=0;j<m;j++){
            merged.push_back(nums2[j]);
        }
        sort(begin(merged),end(merged));
        int x=merged.size();
        float ans=0;
        if(x%2==0){
            ans=float(merged[x/2]+merged[(x/2)-1])/2;
        }
        else{
            ans=float (merged[x/2]);
        }
        return ans;
    }
};

//Optimal approach
//Olog(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        if(n1>n2) return findMedianSortedArrays(nums2,nums1);//because we will peroform binary search on array of smaller size
        int low=0;
        int high=n1;
        int n=n1+n2;
        int left=(n1+n2+1)/2;
        while(low<=high){
            int mid1=(low+high+1)/2;
            int mid2=left-mid1;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;

            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(n%2==1) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 0;
    }
};