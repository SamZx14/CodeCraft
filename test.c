#include<stdio.h>
#include<conio.h>
#include<time.h>
#include "g_color.c"
#include "h_consol.c"


const char sm_ar[]={'"','%','&'}; // Array to store special characters for the question
const char *bc = "\n"; // Variable to store the background color
int score = 0; // Global variable to keep track of the score

// Function for andswers navigation
// This function takes the user's input and checks if it matches the correct answer
void ans_nvg(char *ch,int *choice,int *ans,int Ans,int inc,int *stp,const char *op_a, const char *op_b, const char *op_c, const char *op_d){
    
    if (*stp==0) animation("\033[1;32mChoose the correct answer:\n\n\n",3);
    else printf("\033[1;32mChoose the correct answer:\n\n\n");
    if ((*ch == 'd' || *ch == 'D' || *ch == 77) && *choice < 4) (*choice)++;
    else if ((*ch == 'a' || *ch == 'A' || *ch == 75) && *choice > 1) (*choice)--;
    else if ((*ch == 'w' || *ch == 'W' || *ch == 72) && (*choice ==3 || *choice ==4)) *choice-=2;
    else if ((*ch == 'x' || *ch == 'X' || *ch == 80) && (*choice ==1 || *choice ==2)) *choice+=2;
    else if (*ch == '\r' || *ch == 's' || *ch == 'S') {
        if (*choice == 1) *ans = 1; // Option A
        else if (*choice == 2) *ans = 2; // Option B
        else if (*choice == 3) *ans = 3; // Option C
        else if (*choice == 4) *ans = 4; // Option D
       
    }
        // Display the options with color coding
        printf("%s A:%s %s\t",*choice==1?"\033[41m":"\033[1;37m",c2(8),op_a);
        printf("%s B:%s %s\n\n",*choice==2?"\033[41m":"\033[1;37m",c2(8),op_b);
        printf("%s C:%s %s\t",*choice==3?"\033[41m":"\033[1;37m",c2(8),op_c);
        printf("%s D:%s %s\n\n",*choice==4?"\033[41m":"\033[1;37m",c2(8),op_d);
       if((*ch == '\r' || *ch == 's' || *ch == 'S'))
        {
            if (*ans == Ans) {
            score += inc; // Increment score by 10 for correct answer
            animation("\033[1;32mCorrect!\n", 2);
        } else {
            animation("\033[1;31mIncorrect! The correct answer is 5.\n", 2);
            printf("%s\n", bc);
        }
    }
   
    
   
}

int cq1_l1(){ // question 1 for level 1
    pair W_size = get_cnl_wh();
    int choice =1,stp=0,ans=0;
    char ch;
    time_t star=time(NULL);
    system ("cls");
    while(1){
        set_cnl_pos(0,0);
        if(_kbhit() ) {
            system("cls");
            
            ch=_getch();
        }
    
    set_cnl_pos(0,0);
    if(stp==0) animation("\033[1;32mWhat is the correct output for x...\n\n",2);
    else printf("\033[1;32mWhat is the correct output for x...\n\n");
    // Display the question
     printf("%sint %sx %s= 5\n%sprintf%s(%s%c%cd%c,x++%s);\n\n",c2(13),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,1/*ans*/,10/*score increment*/,&stp,"5", "6", "7", "8"); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
    if(time(NULL)-star>=10) {
        printf("time is up");
        break;
    }
    if (ans !=0) break;
    stp++;
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;32mPress any key to continue...", 2);
    _getch();
    return 0;
}







 int main (){ // Main function for the code quiz
    system("cls");
    int choose = 1, stp = 0;
    char ch;
    cq1_l1();


}