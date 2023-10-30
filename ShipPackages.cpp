class Solution {
    int maxArrElement(vector<int>&arr){
    int maxi = INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
int arrSum(vector<int>&arr){
    int sum =0;
    for(int i =0;i<arr.size();i++){
        sum+=arr[i];
    }
    return sum;
}
int calcDays(vector<int>&a,int capacity){
    int days=1;
    int sum=0;
    for(int i=0;i<a.size();i++){
        if(sum+a[i]>capacity){
            days++;
            sum=a[i];
        }
        else{
            sum+=a[i];
        }
    }
    return days;
}
public:
    int shipWithinDays(vector<int>& weights, int d) {
         int low = maxArrElement(weights);
    int high = arrSum(weights);
    int ans=0;
    while(low<=high){
        int mid = (low+high)/2;
        if(calcDays(weights,mid)<=d){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;

    }
};



