class Solution {
    public int maxArea(int[] height) {
        int ptr1=0;
        int ptr2= height.length-1;
        int area=0;
        while(ptr1<ptr2){
            int currArea=(ptr2-ptr1)*Math.min(height[ptr2],height[ptr1]);
            area=Math.max(currArea,area);
            if(height[ptr1]>height[ptr2]){
                ptr2--;
            }else{
                ptr1++;
            }
        }
        return area;
    }
}