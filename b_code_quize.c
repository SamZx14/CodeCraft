#include<stdio.h>
#include<conio.h>

#include "j_game_w.c"

const char sm_ar[]={'"','%','&'};
const char *bc = "\n";


void easy_q();
void medium_q();
void hard_q();

int cq1_l1(){
    system("cls");
    animation("\033[1;32mWhat is the correct output for x...\n\n",2);
    printf("%sint %sx %s= 5\n%sprintf%s(%s%c%cd%c,x++%s);\n\n",c2(13),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));

    return 0;
}


int (*level_1[])() = {cq1_l1, /* other levels can be added here */};
int (*level_2[])() = { /* level 2 functions */ };
int (*level_3[])() = { /* level 3 functions */ };


void easy_q(){
    int i=1;
    while(i--)
    {
       
    }
    animation("\033[1;32mStarting Easy Quiz...\n",2);
}

void medium_q(){
    int i=0;
    while(i--)
    {
        
    }
    animation("\033[1;32mStarting Medium Quiz...\n",2);
}

void hard_q(){
    int i=0;
    while(i--)
    {
        
    }
    animation("\033[1;32mStarting Hard Quiz...\n",2);
}



void code_quiz() {
    system("cls");
    int choose = 1, stp = 0;
    char ch;
    

while (1) {
  
    dis_level(choose, stp++, "CODE QUIZ");
    ch = _getch();
    if ((ch == 'w' || ch == 'W') && choose > 1) choose--;
    else if ((ch == 'x' || ch == 'X') && choose < 4) choose++;
    else if (ch == '\r' || ch == 's' || ch == 'S') {
        if (choose == 1) easy_q();
        else if (choose == 2) medium_q();
        else if (choose == 3) hard_q();
        else if (choose == 4) {
            break;
        }
    }
}
}