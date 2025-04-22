#include<stdio.h>

void mix_mode() {
    system("cls");
    animation("\033[1;32mStarting Mix Mode...\n",2);
    // Implement the Mix Mode game logic here
    c1(11);
        animation("\nPress any key to return to the menu...",2);
        _getch();
        c1(7);
}