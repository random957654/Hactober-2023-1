#include <stdio.h>

int main(){
    int n;
    printf("Enter the no of rows:");
    scanf("%d",&n);
    printf("\n");
    for(int i=0;i<n;i++){
        for (int j=n;j>i;j--){
            printf(" ");
        }
        for(int k=0;k<i+1;k++){
            printf("%d",k+1);
        }
        for(int k=i;k>0;k--){
            printf("%d",k);
        }
        printf("\n");
    }

    return 0;
}