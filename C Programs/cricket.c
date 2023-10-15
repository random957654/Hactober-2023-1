#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int happens, overs = 1, score1 = 0, score2 = 0, wickets1 = 0, wickets2 = 0,
             balls1, balls2, ballType, shotSelection;

int result() {
  if (score1 > score2 || score2 > score1) {
    return 1;
  }
  return 0;
}

int generateRandomNum(int n) {
  srand(time(NULL));
  return rand() % n;
}

int randomNum(int n) {
  srand(time(NULL));
  return rand() % n;
}

int boundary(int n) {
  srand(time(NULL));
  return rand() % n;
}

void circle(int r) {
  int x, y;
  for (int x = -r; x <= r; x++) {
    printf("\t\t\t");
    for (int y = -r; y <= r; y++) {
      if (x * x + y * y - r * r < 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int n, toss, r, option;
char player1Name[10];
char player2Name[10];
char player3Name[10];
char player4Name[10];
char player5Name[10];

int main() {

  printf("\n\t\t\t\tWELCOME TO THE WORLD OF C-CRICKET\n\n");
  printf("Enter your 'PLAYING-5'\n");

  printf("Player-1: ");
  scanf("%s", &player1Name);
  printf("Player-2: ");
  scanf("%s", &player2Name);
  printf("Player-3: ");
  scanf("%s", &player3Name);
  printf("Player-4: ");
  scanf("%s", &player4Name);
  printf("Player-5: ");
  scanf("%s", &player5Name);
  printf("\nYour Team \n\n");
  printf("%s \n", player1Name);
  printf("%s \n", player2Name);
  printf("%s \n", player3Name);
  printf("%s \n", player4Name);
  printf("%s \n", player5Name);

  printf("Enter the size of ground :");
  scanf("%d", &r);

  printf(
      "  It's time for the 'TOSS'\n Press 0 for 'HEADS' and 1 for 'TAILS'\n");
  scanf("%d", &toss);

  if (toss == generateRandomNum(2)) {
    printf("Press 0 to BAT and any other key to Bowl.\n");
    scanf("%d", &option);

    if (option == 0) {
      printf("You won the toss and opted to BAT first.\n");
      circle(r / 5);
      printf("   LET'S BEGIN \n");
      goto innings2;
    } else {
      printf("You won the toss and opted to BOWL first.\n");
      circle(r / 5);
      printf("\t\tLET'S BEGIN \n");
      goto innings1;
    }
  } else {
    printf("Computer will BAT first.\n");
    circle(r / 5);
    printf("   LET'S BEGIN \n");
    goto innings1;
  }

  if (option == 0) {
  innings2:
    printf("\n%s and %s will open the innings.\n", player1Name, player2Name);
    printf("\nPress 0 for 'DEFENCE'    1 for 'DRIVE'   2 for 'LOFTED SHOT' OR "
           "any other NUMBER for any different SHOT\n");
  nextBall2:
    printf("Select your shot.\n");
    scanf("%d", &shotSelection);

    // you

    happens = randomNum(8);

    for (int i = 0; i < 5; i++) {

      for (int j = 1; j < 7; j++) {
        balls2 = balls2 + 1;
        if (balls2 >= 50) {
          goto inningsOver2;
        } else {
          goto match2;
        }
      match2:
        switch (happens) {
        case 0:
          printf(" Good defence , 0 Runs.\n");
          score2 = score2 + 0;
          
          goto nextBall2;
          break;
        case 1:
          printf(" well played for a single, 1 Run.\n");
          score2 = score2 + 1;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall2;
          break;
        case 2:
          printf(" A double here, 2 Runs.\n");
          score2 = score2 + 2;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall2;
          break;
        case 3:
          printf(" Good running between the wickets, 3 Runs.\n");
          score2 = score2 + 3;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall2;
          break;
        case 4:
          printf("  It races to the BOUNDARY, 4 Runs.\n");
          score2 = score2 + 4;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall2;
          break;
        case 5:
          printf(" It goes for MAXIMUM, a %d Meters SIX.. 6 Runs.\n",
                 r + boundary(30));
          score2 = score2 + 6;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall2;
          break;

        default:
          printf("THAT'S OUT..!!!, Bowler strikes.\n");
          wickets2 = wickets2 + 1;
          if (wickets2 == 5) {
            goto inningsOver2;
          } else {
            goto nextBall2;
          }
          break;
        }
      }
    }

  inningsOver2:
    for (int k = 0; k < 90; k++) {
      printf("_");
    }
    printf("\n\n\t\t\t\tINNINGS OVER..!\n\t\t\t\tTOTAL : %d/%d (%d balls)\n\n",
           score2, wickets2, balls2 - 1);
    for (int k = 0; k < 90; k++) {
      printf("_");
    }
    if (score1 > 0) {
      goto result;
    } else {
      goto innings1;
    }
  } else {
  innings1:
    printf("\n%s will open the attack.\n", player5Name);
    printf("\nPress 0 for 'FULL TOSS' Press 1 for 'FULL LENGHT'   Press 2 for "
           "'SHORT BALL'    Press 3 for 'YORKER' OR any other NUMBER for "
           "something different\n");
  nextBall1:
    printf("Select ball type.\n");
    scanf("%d", &ballType);

    // computer

    happens = randomNum(8);

    for (int i = 0; i < 5; i++) {
      overs = overs + 1;
      for (int j = 1; j < 7; j++) {
        balls1 = balls1 + 1;
        if (balls1 >= 50) {
          goto inningsOver1;
        } else {
          goto match1;
        }
      match1:
        switch (happens) {
        case 0:
          printf(" Good defence , 0 Runs.\n");
          score1 = score1 + 0;
          goto nextBall1;
          break;
        case 1:
          printf(" well played for a single, 1 Run.\n");
          score1 = score1 + 1;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall1;
          break;
        case 2:
          printf(" A double here, 2 Runs.\n");
          score1 = score1 + 2;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall1;
          break;
        case 3:
          printf(" Good running between the wickets, 3 Runs.\n");
          score1 = score1 + 3;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall1;
          break;
        case 4:
          printf("  It races to the BOUNDARY, 4 Runs.\n");
          score1 = score1 + 4;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall1;
          break;
        case 5:
          printf(" It goes for MAXIMUM, a %d Meters SIX.. 6 Runs.\n",
                 r + boundary(30));
          score1 = score1 + 6;
          if (result() && score1 != 0 && score2 != 0 && wickets1 == 5 &&
              wickets2 == 5 && balls1 > 49 && balls2 > 49) {
            goto result;
          }
          goto nextBall1;
          break;

        default:
          printf("THAT'S OUT..!!!, Bowler strikes.\n");
          wickets1 = wickets1 + 1;
          if (wickets1 == 5) {
            goto inningsOver1;
          } else {
            goto nextBall1;
          }
          break;
        }
      }
    }

  inningsOver1:
    for (int k = 0; k < 90; k++) {
      printf("_");
    }
    printf("\n\n\t\t\t\tINNINGS OVER..!\n\t\t\t\tTOTAL : %d/%d (%d balls)\n\n",
           score1, wickets1, balls1);
    for (int k = 0; k < 90; k++) {
      printf("_");
    }

    if (score2 > 0) {
      goto result;
    } else {
      goto innings2;
    }
  }

result:
  if (score1 > score2) {
    printf("\n\t\t\tCOMPUTER won the match. WELL TRIED..!\n\n");
  } else {
    printf("\n\t\t\tYOU won the match. CONGRATULATIONS..!!\n\n");
  }

  return 0;
}
