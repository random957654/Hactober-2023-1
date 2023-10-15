#include<Stdio.h>
void main(){
int n;
printf("enter n:");
scanf("%d",&n);
for(int i=2;i<n;i++){
    if(n%i!=0){
        if(n%4==1){
            printf("yes");
            break;
        }
    }
    else{
        printf("no");
        break;
    }
}
}
