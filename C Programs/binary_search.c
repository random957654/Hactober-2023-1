#include <stdio.h>
#include<stdlib.h>
int binary_search(int a[],int beg,int end,int c);
int main(){
    int n;
    printf("Enter the length of list : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of list : ");
     for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
            }
    int item;
    printf("enter the element you want to search : ");
    scanf("%d",&item);
    int pos;
    int strt=1;
    pos=binary_search(arr,strt,n,item);
    printf("%d",pos);
    if(pos==-1){
        printf("search unsuccesful .;");
    }    
    else{
        printf("the element is on %d location of array",pos);
    }
    return 0;
}
int binary_search(int a[],int beg,int end,int c){
    int mid;
    while(beg<=end){
    mid=(end+beg)/2;
        if(a[mid] == c){
            return mid;
        }
        else if(a[mid]< c){
            beg=mid+1;
        }
        else{
            end=mid-1;
        

    }
}
return -1;
}