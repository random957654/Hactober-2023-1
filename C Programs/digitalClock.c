#include <stdio.h>

int main() {
  printf("Welcome\n");
  int hour_hand, minute_hand, phase;
  printf("\n\aMORNING PHASE = 1 \nwhile \nEVENING PHASE = 2\n\n");
  printf("WHICH PHASE OF DAY IT IS:\n\a\n");
  scanf("%d", &phase);

  switch (phase) {
  case 1:

    printf("Enter the number that hour hand passed\n");
    scanf("%d", &hour_hand);
    printf("Enter the number that minute hand passed\n");
    scanf("%d", &minute_hand);
    if (hour_hand < 13 && minute_hand < 13) {

      printf("The time according to your inputs is %d:%d AM\n", hour_hand,
             5 * minute_hand);
    }

    break;

  case 2:
    printf("Enter the number that hour hand passed\n");
    scanf("%d", &hour_hand);
    printf("Enter the number that minute hand passed\n");
    scanf("%d", &minute_hand);
    if (hour_hand < 13 && minute_hand < 13) {
      printf("The time according to your inputs is %d:%d PM\n", hour_hand,
             5 * minute_hand);
    }

    break;

  default:
    printf("Please enter valid numbers..!");

    break;
  }

  return 0;
}