#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  char userChoice = 'z';

  while (userChoice != 'q' && userChoice != 'Q') {
    printf("A: ls \n");
    printf("B: ps \n");
    printf("C: who \n");
    printf("Q: quit \n");
    printf("Enter a command: ");
    scanf(" %c", &userChoice);

    pid = fork();
    if (pid == 0) {
      switch (userChoice) {
      case 'a':
      case 'A':
        execlp("/bin/ls", "ls", NULL);
        break;
      case 'b':
      case 'B':
        execlp("/bin/ps", "ps", NULL);
        break;
      case 'c':
      case 'C':
        execlp("/usr/bin/whoami", "who", NULL);
        break;
      case 'q':
      case 'Q':
        exit(0);
      default:
        printf("Invalid choice\n");
        break;
      }
    } else if (pid > 0) {
      wait(NULL);
    } else {
      perror("fork");
    }
  }

  printf("Goodbye!\n");
  return 0;
}