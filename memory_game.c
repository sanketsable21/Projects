#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sequence[100], userAnswer, level = 1, correct = 1;

    // Seed the random number generator
    srand(time(0));

    printf("Welcome to the Memory Game!\n");
    printf("Memorize and recall the sequence of numbers.\n");

    while (correct && level <= 10) {
        printf("Level %d: ", level);
        for (int i = 0; i < level; i++) {
            sequence[i] = rand() % 10;  // Generate a random digit (0-9)
            printf("%d ", sequence[i]); // Display the number
        }
        printf("\n");

        // Wait a few seconds (simulation in terminal game; can use sleep in real system)
        printf("Memorize the sequence...\n");
        getchar();  // Wait for user input (enter) to simulate time passing

        // Ask the user to recall the sequence
        printf("Enter the sequence: ");
        for (int i = 0; i < level; i++) {
            scanf("%d", &userAnswer);
            if (userAnswer != sequence[i]) {
                correct = 0;  // User gave the wrong answer
                break;
            }
        }

        if (correct) {
            printf("Correct! Moving to the next level...\n\n");
            level++;
        } else {
            printf("Wrong! Game over. You reached level %d.\n", level);
        }
    }

    return 0;
}
