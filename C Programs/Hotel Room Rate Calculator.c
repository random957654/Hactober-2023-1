/*user to enter the type of the room, accommodation type ( F- Full 
Board, H- Half Board ), number of days and the Card type ( G, S, B ) and calculate the amount 
need to be paid for the given no of days. */
#include <stdio.h>

int main (void){
	int typeOfRoom,days;
	float amount,discount;
	char boardingType, cardType;
	
	printf("Enter Room Type:");
	scanf("%d",&typeOfRoom);
		
		if (typeOfRoom<1 || typeOfRoom>3)
		{
			printf("Invalid Room Type\n\n");
			printf("Enter Room Type:");
			scanf("%d" ,&typeOfRoom);
		
		}
		
	printf ("Enter Accommodation Basis (F/H):");
	scanf(" %c", &boardingType);
	
	printf ("Number of Days:");
	scanf("%d",&days);
	
	 if (boardingType=='F')
	 {
		if(typeOfRoom==1)
		{
			amount = 25555*days;
						
		}
		else if (typeOfRoom==2)
		{
			amount= 17500*days;
		}
		else if(typeOfRoom==3)
		{
			amount = 9000*days;
		}
	 }
	else if(boardingType=='H')
	 {
		if (typeOfRoom==1)
		{
			amount= 17250*days;
		}
		else if (typeOfRoom==2)
		{
			amount= 12250*days;
		}
		else if (typeOfRoom==3)
		{
			amount= 7250*days;
		}
	 }
	else 
	 {
		printf("Invalid Accomodation Basis");
	 }
	
	printf("Enter your reward card type (G/S/B):");
	scanf(" %c",&cardType);
	
	if(cardType=='G'|| cardType=='g')
	 {
		discount = amount*0.125;
	 }
	else if(cardType=='S'|| cardType=='s')
	 {
		discount = amount*0.115;
	 }
	else 
	 {
		discount= amount*0.095;
	 }
	 printf("Amount (Rs.): %.2f\n\n",amount-discount);
	 printf("Enter type of room:");
	 scanf("%d", &typeOfRoom);		
		
	return 0;	
}
















