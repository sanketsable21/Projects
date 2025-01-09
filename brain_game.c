#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, answer, userAnswer, correctAnswers = 0, totalQuestions = 5, operation;
    char operations[] = {'+', '-', '*'};
    
    // Seed the random number generator
    srand(time(0));

    printf("Welcome to the Brain Game: Math Quiz!\n");
    printf("You will be asked %d random math questions.\n", totalQuestions);
    printf("Try to answer as many correctly as possible!\n\n");

    // Loop to generate and ask questions
    for (int i = 0; i < totalQuestions; i++) {
        // Generate two random numbers between 1 and 10
        num1 = rand() % 10 + 1;
        num2 = rand() % 10 + 1;

        // Randomly select an operation (+, -, *)
        operation = rand() % 3;

        // Calculate the correct answer
        switch (operations[operation]) {
            case '+': 
                answer = num1 + num2; 
                break;
            case '-': 
                answer = num1 - num2; 
                break;
            case '*': 
                answer = num1 * num2; 
                break;
        }

        // Ask the question
        printf("Question %d: %d %c %d = ?\n", i + 1, num1, operations[operation], num2);

        // Get user's answer
        printf("Your answer: ");
        scanf("%d", &userAnswer);

        // Check if the answer is correct
        if (userAnswer == answer) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Wrong! The correct answer was %d.\n", answer);
        }
        printf("\n");
    }

    // Display final score
    printf("You answered %d out of %d questions correctly!\n", correctAnswers, totalQuestions);

    // Provide feedback based on performance
    if (correctAnswers == totalQuestions) {
        printf("Excellent! You're a math genius!\n");
    } else if (correctAnswers >= totalQuestions / 2) {
        printf("Good job! Keep practicing!\n");
    } else {
        printf("You need more practice! Keep trying!\n");
    }

    return 0;
}
