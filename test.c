#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>  // For _getch() function

// Function to ask a question and apply time limit with navigation
int ask_question(const char *question, const char *op_a, const char *op_b, const char *op_c, const char *op_d, int correct_answer, double time_limit) {
    time_t start_time, current_time;
    int choice = 1, ans = 0;
    char ch;

    printf("%s\n", question); // Display the question

    // Display options with navigation
    printf("Use Arrow keys to navigate and Enter to select.\n");

    time(&start_time);  // Start the timer for this question

    // Loop to wait for user's answer or timeout
    while (1) {
        time(&current_time);  // Get current time
        double elapsed_time = difftime(current_time, start_time);  // Calculate elapsed time

        // If time exceeds the limit, return timeout
        if (elapsed_time >= time_limit) {
            printf("\nTime's up! Moving to the next question.\n");
            return 0;  // Timeout, no answer selected
        }

        // Clear options and re-display question and options with updated choice
        system("cls");
        printf("%s\n", question); // Display the question
        printf("Use Arrow keys to navigate and Enter to select.\n");

        // Display options with color coding
        printf("%s A: %s %s\n", choice == 1 ? "->" : "  ", op_a, (choice == 1) ? "<-" : "");
        printf("%s B: %s %s\n", choice == 2 ? "->" : "  ", op_b, (choice == 2) ? "<-" : "");
        printf("%s C: %s %s\n", choice == 3 ? "->" : "  ", op_c, (choice == 3) ? "<-" : "");
        printf("%s D: %s %s\n", choice == 4 ? "->" : "  ", op_d, (choice == 4) ? "<-" : "");

        // Get user input for navigation
        ch = _getch(); // Get user input

        // Navigate through the choices using arrow keys
        if (ch == 72 && choice > 1) { // Up Arrow (ASCII 72)
            choice--;
        } else if (ch == 80 && choice < 4) { // Down Arrow (ASCII 80)
            choice++;
        } else if (ch == '\r' || ch == 's' || ch == 'S') { // Enter or 'S' to select answer
            ans = choice; // Store the selected answer
            break; // Exit the loop after selection
        }
    }

    // Check if the selected answer is correct
    if (ans == correct_answer) {
        printf("\nCorrect answer!\n");
        return 1; // Correct answer
    } else {
        printf("\nIncorrect! The correct answer was %c.\n", 'A' + correct_answer - 1);
        return 0; // Incorrect answer
    }
}

// Main function for the quiz game
int main() {
    int score = 0;
    double time_limit = 30.0; // Set the time limit per question (in seconds)

    // Display welcome message
    printf("Welcome to the Quiz Game!\n");
    printf("You have %lf seconds to answer each question.\n\n", time_limit);

    // Question 1
    score += ask_question(
        "What is the capital of France?",
        "London", "Paris", "Berlin", "Madrid",
        2, // Correct answer is B (Paris)
        time_limit
    );

    // Question 2
    score += ask_question(
        "What is the square root of 16?",
        "3", "4", "5", "6",
        2, // Correct answer is B (4)
        time_limit
    );

    // Question 3
    score += ask_question(
        "Who wrote 'Hamlet'?",
        "Shakespeare", "Dickens", "Austen", "Tolkien",
        1, // Correct answer is A (Shakespeare)
        time_limit
    );

    // Final score display
    printf("\nYour final score: %d\n", score);

    // End of the game
    printf("\nThanks for playing! Press any key to exit...\n");
    _getch();  // Wait for user input before closing
    return 0;
}
