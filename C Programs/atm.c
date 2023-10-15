#include<stdio.h>
int main()
{
int pass=2584, bal=20000, entry, usrpass, usrch, usrbal, ip;
//Password is 2584//
printf("--------------------------------\n");
printf("\tInsert Your Card");
printf("\nPress 1 to Confirm Card Entry.\n");
printf("--------------------------------");
printf("\nType Confirmation : ");
scanf("%d", & entry);

if (entry==1){
	printf("\nCard Accepted Successfully.");
	printf("\n--------------------------------");
	printf("\nEnter Your Password : ");
	scanf("%d",&usrpass);
	if(usrpass==pass){
		printf("--------------------------------");
		printf("\n\tWelcome to SBI\n");
		printf("\n1)Withdraw\t2)Check Balance");
		printf("\n--------------------------------");
		printf("\nEnter Your Choice : ");
		scanf("%d",&usrch);
		printf("--------------------------------");
		switch(usrch){
			case 1:
				printf("\nAvailable Notes : 100 \t200");
				printf("\n                  500 \t2000");
				printf("\n--------------------------------");
				printf("\nEnter Your Amount : ");
				scanf("%d",&usrbal);
				if(usrbal>bal){
					printf("\n--------------------------------");
					printf("\nInsufficiant Balance.");
				}
				else{
					printf("--------------------------------");
					printf("\nTransection Successful....");
					bal=(bal-usrbal);
					printf("\n--------------------------------");
					
					//Note Calculation Part//
					
					printf("\n No. of 2000 note : %d",usrbal/2000);
					usrbal=usrbal%2000;
					printf("\n No. of 500 note : %d",usrbal/500);
					usrbal=usrbal%500;
					printf("\n No. of 200 note : %d",usrbal/200);
					usrbal=usrbal%200;
					printf("\n No. of 100 note : %d",usrbal/100);
					usrbal=usrbal%100;
				}
			break;
			case 2:
				printf("\nYour Account Balance is %d",bal);
			break;
			default:
				printf("\nWrong Input");
			break;
		}
	}
}
else{
printf("You Had not Inserted Your Card\n");
}
}
