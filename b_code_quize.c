#include<stdio.h>
const char sm_ar[]={'"','%','&'};
const char *bc = "\n";
// start = Sayem- new code quize - problem set_1 - 22/04/25
int cq1_l1();
// end = Sayem- new code quize - problem set_1 - 22/04/25
void code_quiz() {
    system("cls");
    c1(6);
    printf("Starting Code Quiz...\n");
    // Implement the Code Quiz game logic here
    c1(3);
    // start = Sayem- new code quize - problem set_1 - 22/04/25
    printf("Enter any key to open game\n");
    _getch();
    cq1_l1();
    // end = Sayem- new code quize - problem set_1 - 22/04/25
            printf("\nPress any key to return to the menu...\n");
            
            
        _getch();
        c1(7);
}
// start = Sayem- new code quize - problem set_1 - 22/04/25
int cq1_l1(){
 printf("int x = 5\nprintf(%c%cd%c,x++);\n\n",sm_ar[0],sm_ar[1],sm_ar[0]);
 return 0;
}
// end = Sayem- new code quize - problem set_1 - 22/04/25
