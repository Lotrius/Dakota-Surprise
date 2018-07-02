#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void loadBar() {
  const int LOADING_ARRAY = 61;
  const int LOADING_BAR_SIZE = LOADING_ARRAY - 1;

  char loadingBar[LOADING_ARRAY];
  memset(loadingBar, ' ', LOADING_ARRAY*sizeof(char));
  loadingBar[LOADING_BAR_SIZE] = '\0';

  srand(time(0));

  int numA =  rand() % (40 - 11) + 10;

  for(int i = 0; i < LOADING_BAR_SIZE; i++) {
    if(i < numA) {
      loadingBar[i] = 'a';
    } else {
      loadingBar[i] = 'h';
    }

    printf("\rLoading: [%s] | %3d%%\0",loadingBar, ((i+1)*100) / LOADING_BAR_SIZE);
    fflush(stdout);

    int sleepTime = rand() % 250000;
    usleep(sleepTime);
  }
  putchar('\n');
}

void openPage() {
  for(int i = 5; i >= 0; i--) {
    printf("\rOpening surprise in %d", i);
    fflush(stdout);
    usleep(1000000);
  }
  putchar('n');

  system("explorer https://htmlpreview.github.io/?https://github.com/Somesk278/Dakota-Birthday/blob/master/HTML%20Surprise/index.html");
}

int main() {
  loadBar();
  printf("Download complete.\n");
  openPage();
  return 0;
}
