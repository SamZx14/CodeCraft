#include<stdio.h>
#include<conio.h>
#include<time.h>


const char sm_ar[]={'"','%','&'}; // Array to store special characters for the question
const char *bc = "\n"; // Variable to store the background color
int score = 0; // Global variable to keep track of the score

// Function for andswers navigation
// This function takes the user's input and checks if it matches the correct answer
void ans_nvg(char *ch,int *choice,int *ans,int Ans,int inc,int *stp,const char *op_a, const char *op_b, const char *op_c, const char *op_d){
    
    if (*stp==0) animation("\033[1;32mChoose the correct answer:\n\n\n",3);
    else printf("\033[1;32mChoose the correct answer:\n\n\n");
    
        // Display the options with color coding
        printf("%s A:%s %s\t",*choice==1?"\033[41m":"\033[1;37m",c2(8),op_a);
        printf("%s B:%s %s\n\n",*choice==2?"\033[41m":"\033[1;37m",c2(8),op_b);
        printf("%s C:%s %s\t",*choice==3?"\033[41m":"\033[1;37m",c2(8),op_c);
        printf("%s D:%s %s\n\n",*choice==4?"\033[41m":"\033[1;37m",c2(8),op_d);
      
    *ch= _getch(); // Get user input
    // Check for valid input and update the choice accordingly
    if ((*ch == 'd' || *ch == 'D' || *ch == 77) && *choice < 4) (*choice)++;
    else if ((*ch == 'a' || *ch == 'A' || *ch == 75) && *choice > 1) (*choice)--;
    else if ((*ch == 'w' || *ch == 'W' || *ch == 72) && (*choice ==3 || *choice ==4)) *choice-=2;
    else if ((*ch == 'x' || *ch == 'X' || *ch == 80) && (*choice ==1 || *choice ==2)) *choice+=2;
    else if (*ch == '\r' || *ch == 's' || *ch == 'S') {
        if (*choice == 1) *ans = 1; // Option A
        else if (*choice == 2) *ans = 2; // Option B
        else if (*choice == 3) *ans = 3; // Option C
        else if (*choice == 4) *ans = 4; // Option D
        if (*ans == Ans) {
            score += inc; // Increment score by 10 for correct answer
            high_score_w(score, 1); // Update high score for code quiz
            animation("\033[1;32mCorrect!\n", 2);
            dis_score("CODE QUIZ",1,score,1,1,3); // Update score display
        } else {
            animation("\033[1;31mIncorrect! The correct answer is 5.\n", 2);
            printf("%s\n", bc);
        }
    }
   
}

void easy_q(); // Function prototypes for different difficulty levels
void medium_q(); // Function prototypes for different difficulty levels 
void hard_q(); // Function prototypes for different difficulty levels

int cq1_l1(){ // question 1 for level 1
    pair W_size = get_cnl_wh();
    int choice =1,stp=0,ans=0;
    char ch;
    while(1){
    system("cls");
    dis_score("CODE QUIZ",1/*round */,score,1/*high score index*/,1,3); // pass the game name, round number, current score, high score index, level, and life
    set_cnl_pos(0,7);
    if(stp==0) animation("\033[1;32mWhat is the correct output for x...\n\n",2);
    else printf("\033[1;32mWhat is the correct output for x...\n\n");
    // Display the question
    printf("%sint %sx %s= 5\n%sprintf%s(%s%c%cd%c,x++%s);\n\n",c2(13),c2(15),c2(8),c2(7),c2(8),c2(6),sm_ar[0],sm_ar[1],sm_ar[0],c2(8));
    
    ans_nvg(&ch,&choice,&ans,1/*ans*/,10/*score increment*/,&stp,"5", "6", "7", "8"); //here 1st is choice, 2nd is ans, 3rd is correct ans, 4th is stp, 5th is option a, 6th is option b, 7th is option c, 8th is option d
    if (ans !=0) break;
    stp++;
    }
    set_cnl_pos(0,(W_size.y)-2);
    animation("\033[1;32mPress any key to continue...", 2);
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
    int i=1;
    while(i--)
    {
       level_1[i]();

    }
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