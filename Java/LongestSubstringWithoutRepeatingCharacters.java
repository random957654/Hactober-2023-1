class Solution {
    public int lengthOfLongestSubstring(String s) {
        int arr[] = new int[256];
        for(int i=0;i<256;i++){
            arr[i] = -1;
        }
        int st = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            int index = ch;
            if(arr[index] == -1){
                arr[index] = i;
            }else{
                if(st<=arr[index]){
                    ans = Math.max(ans,i-st);
                    st = arr[index]+1;
                    arr[index] = i;
                }else{
                    arr[index] = i;
                }
                
            }
        }
        ans = Math.max(ans,s.length() - st);
        return ans;
    }
}