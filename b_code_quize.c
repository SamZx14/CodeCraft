#include<stdio.h>
#include<conio.h>

const char sm_ar[]={'"','%','&'};
const char *bc = "\n";
int stp=0;
int cq1_l1(){

    system("cls");
    animation("\033[1;32mWhat is the correct output for x...\n\n",2);
    printf("%sint %sx %s= 5\n%sprintf%s(%s%c%cd%c,x++%s);\n\n",c2(13),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));

    dis_nvg(&stp);
    return 0;
   }
void code_quiz() {
    system("cls");
    c1(6);
    animation("Starting Code Quiz...\n",2);
    c1(3);
    animation("Enter any key to open game\n",2);
    _getch();
    cq1_l1();
  
    animation("\nPress any key to return to the menu...\n",2);
     _getch();
     c1(7);
}