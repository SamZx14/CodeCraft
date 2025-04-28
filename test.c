#include <stdio.h> 
#include "j_game_w.c" 


    int main() {
        int choose = 1, stp = 0;
        char ch;
    while (1) {
      
      
        dis_level(choose, stp++, "CODE QUIZ");
        ch = _getch();
        if ((ch == 'w' || ch == 'W') && choose > 1) choose--;
        else if ((ch == 'x' || ch == 'X') && choose < 4) choose++;
        else if (ch == '\r' || ch == 's' || ch == 'S') {
            if (choose == 1) ;
            else if (choose == 2) ;
            else if (choose == 3) ;
            else if (choose == 4) {
                break;
            }
        }
    }
        return 0;
    }

