class Solution {
public:

int calcMin(vector<int>&v){
	int n = v.size();
	int mini = INT_MAX;
	for(int i =0;i<n;i++){
		mini = min(mini,v[i]);
	}
	return mini;
}
int calcMax(vector<int>&v){
	int n = v.size();
	int maxi = INT_MIN;
	for(int i =0;i<n;i++){
		maxi = max(maxi,v[i]);
	}
	return maxi;
}
bool ifPossible(vector<int>&a,int k,int m,int days){
	int n = a.size();
	int c=0;
	int totalNoB=0;
	for(int i=0;i<n;i++){
		if(a[i]<=days){
			c++;
		}
		else{
			totalNoB += (c/k);
			c=0;
		}
	}
	totalNoB += (c/k);
	if(totalNoB>=m){
		return true;
	}
	else{
		return false;
	}
}
        int minDays(vector<int>& arr, int m, int k) {
        int low = calcMin(arr);
	int high = calcMax(arr);
	int ans = -1;
            long long mul = (long long)k*m;
	if(mul>arr.size()) return -1;
	while(low<=high){
		int mid = (low+high)/2;
		if(ifPossible(arr,k,m,mid)){
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