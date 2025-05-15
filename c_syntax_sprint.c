#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int score_s=0;

void check_ans(int round,int high_si,int level,int time_limit,int *life,int *complite_syntax,int ans_pos_x,int ans_pos_y,int data_pos,const char *ans,const char *explanation){ // Function to check the answer
    data_pos+=2;
    pair W_size = get_cnl_wh();
    c1(11);
    animation("\n\nType your answer here to complete the code and level up!",3); // Prompt the user to type their answer
    time_t start = time(NULL),time_diff; // Start the timer
     char in_ans[10]; // Variable to store the user's input
    while(1){
     
      time_diff =time(NULL)-start; // Calculate the time difference
       set_cnl_pos(W_size.x-11,5);
       printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
       if(_kbhit()){ // Check if a key is pressed
        set_cnl_pos(ans_pos_x,ans_pos_y);
        c1(3);
        scanf("%s",&in_ans);
         set_cnl_pos(W_size.x-11,5);
         time_diff =time(NULL)-start;
         printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer

         if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
               set_cnl_pos(0,data_pos);
                animation("\033[1;31mTime Up\033[0m",4);
      
        }
        else if(strcmp(ans,in_ans)==0){ // Check if the user's answer is correct
              score_s+=10; // Increment score by 10 for correct answer
              (*complite_syntax)++; // Increment the completed syntax count
              high_score_w(score_s,high_si);
              dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life); // Display the score
              set_cnl_pos(0,data_pos);
              animation("\033[1;32mCorrect!", 2); 
        }
        else { // If the answer is incorrect
            
              high_score_w(score_s,high_si);
              dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life); // Display the score
              ( *life)--;
              dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
              set_cnl_pos(0,data_pos);
              animation("\033[1;31mIncorrect!", 2);

        }
        break;
      }
      if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
               set_cnl_pos(0,data_pos);
            animation("\033[1;31mTime Up\033[0m",4);
            break;
        }
     
    }
      
     c1(10);
      set_cnl_pos(0,data_pos+2);
    if(strcmp(ans,in_ans)!=0){ // If the answer is incorrect
        animation("For the explanation press Y, else press N\n",3);
    char ex_ch=_getch();
    if(ex_ch=='y'||ex_ch=='Y') { // If the user wants to see the explanation
        animation(explanation,4);
    }
    }
    set_cnl_pos(0,(W_size.y)-4);
    animation("\033[1;34mPress for next round...\033[0m",3);
    _getch();
    
}

int ss1_l1(int *life){
    pair W_size = get_cnl_wh();
    int round=1,level=1,high_si=2,time_limit=20,complite_syntax=0;
    const char *ans="int";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%sint %smain%s () {\n%s___%s i = %s0%s; %s// what is should be placed here ?\n%swhile%s (i < %s10%s) {\n%sprintf (%s%c%cd%c,%s i);\ni++;\n}\n%sreturn %s0%s;\n}",c2(13),c2(10),c2(16),c2(13),c2(16),c2(2),c2(8),c2(6),c2(13),c2(16),c2(2),c2(16),c2(12),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(2),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,0,10,20,ans,"\033[0;33mThe blank should be filled with \033[1;34mint\033[0;33m because \033[1;37mi\033[0;33m is an integer variable, and \033[1;34\033[0;33mint is used to declare integer types in \033[1;35mC."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int(*level_seasy[])() = {ss1_l1, /* other levels can be added here */}; // Array of function pointers for level 1 questions
int(*level_smedium[])() = {/* level 2 functions */}; // Array of function pointers for level 2 questions
int(*level_shard[])() = {/* level 3 functions */}; // Array of function pointers for level 3 questions

void score_board_s(int complite_syntax, int life){ // Function to display the score board
pair W_size = get_cnl_wh();
    system("cls");
    
    set_cnl_pos((W_size.x/2)-4,0);
    printf("%sCODECRAFT\n\n",c2(15));
     set_cnl_pos((W_size.x/2)-7,(W_size.y/2)-4);
     if(life==0) animation("\033[1;31mGAME OVER 0_0",2);
     else        animation("\033[1;31mGAME COMPLITE",2);
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2)-2);
     printf("%sYour current score: %02d%s",c2(15),score_s,c2(0));
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2)-1);
     printf("%sYour High score: %02d%s",c2(15),high_score_r(2),c2(0));
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2));
     printf("%sYour Complite Syntax: %02d%s",c2(15),complite_syntax,c2(0));
     set_cnl_pos((W_size.x/2)-12,(W_size.y/2)+2);
     animation("\033[1;34mPress any key for next...\033[0m",3);
     _getch();
score_s=0;
}
void easy_s(){ // Function for easy syntax
pair W_size = get_cnl_wh();
set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+4);
animation("\033[1;32mStarting Easy Syntax...\n",2);
int life=3,complite_syntax;
for(int i=0;i<1;i++){
   complite_syntax= level_seasy[i](&life);
   if(life==0)break;
}
score_board_s(complite_syntax,life); // Call the score board function
}

void medium_s(){ // Function for medium syntax
pair W_size = get_cnl_wh();
set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+4);
animation("\033[1;32mStarting Medium Syntax...\n",2);
int life=3,complite_syntax;
for(int i=0;i<1;i++){
   complite_syntax= level_smedium[i](&life);
   if(life==0)break;
}
score_board_s(complite_syntax,life); // Call the score board function
}

void hard_s(){ // Function for hard syntax
pair W_size = get_cnl_wh();
set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+4);
animation("\033[1;32mStarting Hard Syntax...\n",2);
int life=3,complite_syntax;
for(int i=0;i<1;i++){
   complite_syntax= level_shard[i](&life);
   if(life==0)break;
}
score_board_s(complite_syntax,life); // Call the score board function
}


void  syntax_sprint() { // Main function for the syntax sprint
    system("cls");
    int choose=1,stp=0;
    char ch='1';
    while(1){
    dis_level(choose,stp++,"SYNTAX S-PRINT"); // Display the level selection menu
    ch=_getch();
    if((ch == 'w' || ch == 'W' || ch == 72) && choose > 1) choose--;
    else if((ch == 'x' || ch == 'X' || ch == 80) && choose < 4) choose++;
    else if(ch == 's' || ch == 'S' || ch == '\r'){
        if(choose == 1)easy_s();
        else if(choose == 2)medium_s();
        else if(choose == 3)hard_s();
        else if(choose == 4)break;
    }
    }
}