#include<stdio.h>
#include<conio.h>

#include "j_game_w.c"

const char sm_ar[]={'"','%','&'};
const char *bc = "\n";

void chose_ans(int choice,int *stp,const char *op_a, const char *op_b, const char *op_c, const char *op_d){
    if (*stp==0) animation("\033[1;32mChoose the correct answer:\n\n\n",3);
    else printf("\033[1;32mChoose the correct answer:\n\n\n");
    

        printf("%s A:%s %s\t",choice==1?"\033[41m":"\033[1;37m",c2(8),op_a);
        printf("%s B:%s %s\n\n",choice==2?"\033[41m":"\033[1;37m",c2(8),op_b);
        printf("%s C:%s %s\t",choice==3?"\033[41m":"\033[1;37m",c2(8),op_c);
        printf("%s D:%s %s\n\n",choice==4?"\033[41m":"\033[1;37m",c2(8),op_d);
      
    }
void ans_nvg(char ch,int *choice,int *ans){
    if ((ch == 'd' || ch == 'D') && *choice < 4) (*choice)++;
    else if ((ch == 'a' || ch == 'A') && *choice > 1) (*choice)--;
    else if ((ch == 'w' || ch == 'W') && (*choice ==3 || *choice ==4)) *choice-=2;
    else if ((ch == 'x' || ch == 'X') && (*choice ==1 || *choice ==2)) *choice+=2;
    else if (ch == '\r' || ch == 's' || ch == 'S') {
        if (*choice == 1) {
            *ans =1;
        }
        else if (*choice == 2) {
            *ans = 2;
        }
        else if (*choice == 3) {
            *ans = 3;
        }
        else if (*choice == 4) {
            *ans = 4;
        }
    }
}

void easy_q();
void medium_q();
void hard_q();

int cq1_l1(){
    int choice =1,stp=0,ans=0;
    char ch;
    while(1){
    system("cls");
    dis_score("CODE QUIZ",1,0,100,1,10);
    pair W_size = get_cnl_wh();
    set_cnl_pos(0,7);
    if(stp==0) animation("\033[1;32mWhat is the correct output for x...\n\n",2);
    else printf("\033[1;32mWhat is the correct output for x...\n\n");

    printf("%sint %sx %s= 5\n%sprintf%s(%s%c%cd%c,x++%s);\n\n",c2(13),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    chose_ans(choice,&stp,"5", "6", "7", "8");
    ch = _getch();
    ans_nvg(ch,&choice,&ans);
    if (ans !=0) break;
    stp++;
    }
    if (ans == 1) {
        animation("\033[1;32mCorrect!\n", 2);
        printf("%s\n", bc);
    } else {
        animation("\033[1;31mIncorrect! The correct answer is 5.\n", 2);
        printf("%s\n", bc);
    }
    animation("\033[1;32mPress any key to continue...\n", 2);
    _getch();
    return 0;
}


int (*level_1[])() = {cq1_l1, /* other levels can be added here */};
int (*level_2[])() = { /* level 2 functions */ };
int (*level_3[])() = { /* level 3 functions */ };


void easy_q(){
    animation("\033[1;32mStarting Easy Quiz...\n",2);
    int i=1;
    while(i--)
    {
       level_1[i]();

    }
   
}

void medium_q(){
    int i=0;
    animation("\033[1;32mStarting Medium Quiz...\n",2);
    while(i--)
    {
        
    }
    
}

void hard_q(){
    int i=0;
    animation("\033[1;32mStarting Hard Quiz...\n",2);
    while(i--)
    {
        
    }
   
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