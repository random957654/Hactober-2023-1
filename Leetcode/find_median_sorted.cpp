class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int merged[n];
        int mid = n/2;
        double median;
        int i = 0, j = 0, k = 0;
        int count = 0, curr;
        while(count<n){
            if(i<nums1.size() and j<nums2.size()){
                if(nums1[i]<=nums2[j]){
                    curr = nums1[i++];
                }
                else{
                    curr = nums2[j++];
                }
            }
            else if(i<nums1.size()){
                curr = nums1[i++];
            }
            else{
                curr = nums2[j++];
            }
            merged[k++] = curr;
            count++;
        }
        if(n%2==0){
            median = merged[mid] + merged[mid-1];
            median /= 2;
        }
        else{
            median = merged[mid];
        }
        return median;
    }
};
