#include<stdio.h>
#include<conio.h>
#include<time.h>


const char sm_ar[]={'"','%','&'}; // Array to store special characters for the question
const char *bc = "\n"; // Variable to store the background color
int score = 0; // Global variable to keep track of the score

// Function for andswers navigation
// This function takes the user's input and checks if it matches the correct answer
void ans_nvg(char *ch,int *choice,int *ans,int Ans,int inc,int *stp, int round, int high_si, int level, int life, const char *op_a, const char *op_b, const char *op_c, const char *op_d, const char *hint,int *hint_pos){
  

    if (*stp==0) animation("\033[1;32mChoose the correct answer:\n\n\n",3);
    else printf("\033[1;32mChoose the correct answer:\n\n\n");
    if ((*ch == 'd' || *ch == 'D' || *ch == 77) && *choice < 5) (*choice)++;
    else if ((*ch == 'a' || *ch == 'A' || *ch == 75) && *choice > 1) (*choice)--;
    else if ((*ch == 'w' || *ch == 'W' || *ch == 72) && (*choice ==3 || *choice ==4 || *choice == 5)) *choice-=2;
    else if ((*ch == 'x' || *ch == 'X' || *ch == 80) && (*choice ==1 || *choice ==2 || *choice == 3)) *choice+=2;
    
        // Display the options with color coding
        printf("%s A:%s %s\t",*choice==1?"\033[41m":"\033[1;37m",c2(8),op_a);
        printf("%s B:%s %s\n\n",*choice==2?"\033[41m":"\033[1;37m",c2(8),op_b);
        printf("%s C:%s %s\t",*choice==3?"\033[41m":"\033[1;37m",c2(8),op_c);
        printf("%s D:%s %s\n\n",*choice==4?"\033[41m":"\033[1;37m",c2(8),op_d);
        printf("%s E:%s Hint",*choice==5?"\033[41m":"\033[1;37m",c2(7));
        c1(8);
        printf(" (If you take a hit, your lose 5 point and you just take once for a round.)");
        c1(7);
      
    // Check for valid input and update the choice accordingly
    
    if (*ch == '\r' || *ch == 's' || *ch == 'S') {
        if (*choice == 1) *ans = 1; // Option A
        else if (*choice == 2) *ans = 2; // Option B
        else if (*choice == 3) *ans = 3; // Option C
        else if (*choice == 4) *ans = 4; // Option D
        
        if (*ans == Ans) {
            score += inc; // Increment score by 10 for correct answer
            high_score_w(score, 1); // Update high score for code quiz
             set_cnl_pos(0,22);
            animation("\033[1;32mCorrect!", 2);
            dis_score("CODE QUIZ",round,score,high_si,level,life); // Update score display
        }
        else if (*choice == 5&&*hint_pos==0) {
            (*hint_pos)++;
            score -= 5; // Increment score by 10 for correct answer
            high_score_w(score, 1); // Update high score for code quiz
            dis_score("CODE QUIZ",round,score,high_si,level,life);; // Update score display
            set_cnl_pos(0,22);
            printf("%s%s%s",c2(11),hint,c2(0));
        }
        
    }
   
}

void easy_q(); // Function prototypes for different difficulty levels
void medium_q(); // Function prototypes for different difficulty levels 
void hard_q(); // Function prototypes for different difficulty levels

int cq1_l1(int *life,int *game_pos){ // question 1 for level 1
    pair W_size = get_cnl_wh();
    int round=1,high_si=1,level=1,choice =1,stp=0,ans=0,correct_ans=1,time_limit=20,hint_pos=0;                                                                                                                                                                      
    char ch='1';
    system("cls");
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    
    set_cnl_pos(W_size.x-10,5);
    printf("%s Time: %02ds%s",c2(15),time_limit,c2(0)); //initial time display
    
    set_cnl_pos(0,7);
    animation("\033[1;32mWhat is the correct output for x...\n\n",2);
    // Display the question
    printf("%sint %sx %s= 5\n%sprintf%s(%s%c%cd%c,x++%s);\n\n",c2(13),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,1/*correct ans*/,10/*score increment*/,&stp,round,high_si,level,*life,"5", "6", "7", "8","",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is round, 7th is high sore index, 8th is level, 9th is life, 10th is option b, 11th is option c, 12th is option d, 13th is hint
    stp++;
    time_t start = time(NULL); //times count start
    while(1){
         W_size = get_cnl_wh();
        if(_kbhit()){ //condition for only input er allowed to change the display data
            system("cls");
            // set_cnl_pos(0,W_size.y);
            ch=_getch();
    dis_score("CODE QUIZ",round,score,high_si,level,*life); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
   
    printf("\033[1;32mWhat is the correct output for x...\n\n");
    // Display the question
    printf("%sint %sx %s= 5\n%sprintf%s(%s%c%cd%c,x++%s);\n\n",c2(13),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,1/*correct ans*/,10/*score increment*/,&stp,round,high_si,level,*life,"5", "6", "7", "8","++a & a++ are not same. Post-Increment: The value of x is used before it's incremented.",&hint_pos); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
        }
        time_t time_dff=time(NULL)-start; //taking the time different
        set_cnl_pos(W_size.x-10,5);
    printf("%s Time: %02ds%s",c2(15),time_limit-time_dff,c2(0)); // the timer
       
    if (ans !=0) {
       if(ans!=correct_ans)( *life)--;
        break;
    }
    if(time_dff>=time_limit) { // condition for timeout
        set_cnl_pos(0,22);
        animation("\033[1;31mTime Up\033[0m",4);
       ( *life)--;
        break;
    }
   
    }
    dis_score("CODE QUIZ",round,score,high_si,level,*life);
    
    if(ans!=correct_ans){
          set_cnl_pos(0,24);
            animation("\033[1;31mIncorrect! Press Y for explanation, else press N for next\n", 3);
            char exp=_getch();
            if(exp=='y'||exp=='Y') {
                c1(9);
                animation("In the printf function, the x (which is 5) is printed first, then incremented.\nSo, it prints 5 and x becomes 6 after that.",4);
            }

        
    }
    set_cnl_pos(0,(W_size.y)-4);
    if((*life)!=0&&ans!=correct_ans) animation("\033[1;34mpress for next round...\033[0m",3);
    else if (ans==correct_ans) animation("\033[1;34mPress any key for next round...\033[0m",3);
    else animation ("\033[1;31mGAME OVER\033[0m\n\nPress any key to continue...",2);
    _getch();
    
    return 0;
}


int (*level_1[])() = {cq1_l1, /* other levels can be added here */}; // Array of function pointers for level 1 questions
int (*level_2[])() = { /* level 2 functions */ }; // Array of function pointers for level 2 questions
int (*level_3[])() = { /* level 3 functions */ }; // Array of function pointers for level 3 questions


void easy_q(){ // Function for easy quiz
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+4);
    animation("\033[1;32mStarting Easy Quiz...\n",2);
    int life=3;
    for(int i=0;i<1;i++){
        level_1[i](&life,&i);
        if(life==0)break;
    }
     system("cls");
     set_cnl_pos((W_size.x/2)-7,(W_size.y/2)-1);
     animation("\033[1;31mGAME COMPLITE",2);
      set_cnl_pos((W_size.x/2)-12,(W_size.y/2)+2);
       animation("\033[1;34mPress any key for next...\033[0m",3);
       _getch();

   score = 0;
}

void medium_q(){ // Function for medium quiz
    int i=0;
    animation("\033[1;32mStarting Medium Quiz...\n",2);
    while(i--)
    {
        
    }
    
}

void hard_q(){ // Function for hard quiz
    int i=0;
    animation("\033[1;32mStarting Hard Quiz...\n",2);
    while(i--)
    {
        
    }
   
}



void code_quiz() { // Main function for the code quiz
    system("cls");
    int choose = 1, stp = 0;
    char ch;
    

while (1) {
  
    dis_level(choose, stp++, "CODE QUIZ");
    ch = _getch();
    if ((ch == 'w' || ch == 'W' || ch == 72) && choose > 1) choose--;
    else if ((ch == 'x' || ch == 'X' || ch == 80) && choose < 4) choose++;
    else if (ch == '\r' || ch == 's' || ch == 'S') {
        if (choose == 1) easy_q();
        else if (choose == 2) medium_q();
        else if (choose == 3) hard_q();
        else if (choose == 4) {
            break;
        }
    }
}
score = 0; // Reset score after exiting the quiz
}