#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void loadBar() {

  const int LOADING_ARRAY = 51; // Size of the array that represents the loading bar. The extra 1 is for the null terminating character
  const int LOADING_BAR_SIZE = LOADING_ARRAY - 1; // The size of the actual loading bar

  char loadingBar[LOADING_ARRAY];  // Create the character array
  memset(loadingBar, ' ', LOADING_BAR_SIZE*sizeof(char)); // Fill the loading bar with spaces
  loadingBar[LOADING_BAR_SIZE] = '\0'; // Null terminating character

  srand(time(0)); // Set up to be able to generate random numbers

  int numA =  rand() % (30 - 19) + 20; // Random number between 20 and 30 representing number of a's in loading bar

  // Iterate through loading bar
  for(int i = 0; i < LOADING_BAR_SIZE; i++) {
    // Fill numA amount of loading bar with a's, then fill rest with h's
    if(i < numA) {
      loadingBar[i] = 'a';
    } else {
      loadingBar[i] = 'h';
    }


    printf("\rLoading surprise: [%s] | %3d%%",loadingBar, ((i+1)*100) / LOADING_BAR_SIZE); // Print loading bar
    fflush(stdout); // Need to do this so that it actually prints out during the iterations, instead of just waiting until everything ends to print out the finished product

    int sleepTime = rand() % 500001; // Choose a random number between 0 and 0.25 seconds. Apparently doing it this way with just the modulo creates some skew towards certain numbers, but I really don't care
    usleep(sleepTime); // Sleep for sleepTime seconds
  }
  usleep(1000000);

  putchar('\n'); // Newline to not mess up how everything looks
}

void openPage() {
  // Countdown to surprise
  for(int i = 5; i >= 0; i--) {
    printf("\rOpening surprise in %d", i);
    fflush(stdout);
    usleep(1000000);
  }

  putchar('\n'); // We love newlines

  system("xdg-open https://dakota-surprise.firebaseapp.com/");
}

int main() {

  loadBar(); // Display download bar
  printf("Loading complete.\n");
  usleep(1000000);
  openPage(); // Countdown to surprise

  return 0;
}
