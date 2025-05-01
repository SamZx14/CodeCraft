#include <stdio.h> 
#include <string.h> // Include string library for string manipulation
#include <stdlib.h> // Include standard library for system functions
#include <conio.h> // Include conio library for console input/output
#include <windows.h> // Include windows library for console manipulation
// Include custom header for game functions
#include "a1_choose_menu.c" // Include custom header for menu functions

    int main() {
        user(); // Call the user function to handle login or account creation
        system("cls"); // Clear the console screen
        printf("file name: %s\n", filename); // Print the filename for debugging
        
        return 0;
        
    }

