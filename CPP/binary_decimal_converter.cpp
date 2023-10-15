#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
void binary_to_decimal(){
    cout<<"Enter binary to convert it into number"<<endl;
    int n;
    cin>>n;
    int ans=0;
    int i = 1;
    while(n>0){
        if(n%10){
            ans += i;
        }
        i = i << 1;
        n=n/10;
    }
    cout<<"Answer is "<<ans<<endl;
}
void decimal_to_binary(){
    cout<<"Enter number to convert it into binary"<<endl;
    int n;
    cin>>n;
    int ans = 0;
    string t = ""; 
    while(n > 0)
    {
        if(n&1){
            t += '1';
        }else{
            t += '0';
        }
        n = n >> 1;
    }
    reverse(t.begin(),t.end());
    ans = stoi(t);
    cout<<"Answer is " <<ans<<endl;

}
int main(){

    cout<<"Welcome to binary and decimal converter Program"<<endl;
    cout<<"Please Enter Your Choice"<<endl<<"1.Convert Binary into Decimal"<<endl<<"2.Convert Decimal into Binary"<<endl;
    int ch;
    cin>>ch;
     
    switch(ch){

        case 1:  
                    binary_to_decimal();
                    break;
        case 2:  
                    decimal_to_binary();
                    break; 
        default:
                    cout<<"Enter a valid option!"<<endl;
                     break;   

    }
}
