#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int score_s=0;
int back_s=1; // Global variables to store score and back status

void check_ans(int round,int high_si,int level,int time_limit,int *life,int *complite_syntax,int ans_pos_x,int ans_pos_y,int data_pos,const char *ans,const char *explanation){ // Function to check the answer
    data_pos+=3;
    pair W_size = get_cnl_wh();
    c1(11);
    animation("\n\nType your answer here to complete the code and level up!",3); // Prompt the user to type their answer
    time_t start = time(NULL),time_diff; // Start the timer
     char in_ans[10]; // Variable to store the user's input
  
    while(1){
     
      time_diff =time(NULL)-start; // Calculate the time difference
       set_cnl_pos(W_size.x-12,5);
       printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
       if(_kbhit()){ // Check if a key is pressed
        set_cnl_pos(ans_pos_x,ans_pos_y);
        c1(3);
        scanf("%s",&in_ans);
        if(strcmp(in_ans,"@") == 0) {
            back_s=0; // If the user wants to go back, set back_s to 0
            *life = 0; // Set life to 0 to end the game
            return; // Exit the function
        }
         set_cnl_pos(ans_pos_x,ans_pos_y);
         c1(10);
         in_ans[strcspn(in_ans, "\n")] = 0; // Remove the newline character from the input
         set_cnl_pos(W_size.x-12,5);
         time_diff =time(NULL)-start;
         printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
         
         if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
               set_cnl_pos(0,data_pos);
                animation("\033[1;31mTime Up\033[0m",4);
        }
         set_cnl_pos(W_size.x-12,5);
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
    if(ex_ch=='@'){
        back_s=0; // If the user wants to go back, set back_s to 0
        *life = 0; // Set life to 0 to end the game
        return; // Exit the function
    }
    if(ex_ch=='y'||ex_ch=='Y') { // If the user wants to see the explanation
        animation(explanation,4);
    }
    }
    char chr;
    set_cnl_pos(0,(W_size.y)-4);
    animation("\033[1;34mPress for next round...\033[0m",3);
    chr=_getch();
    if(chr=='@'){
        back_s=0; // If the user wants to go back, set back_s to 0
        *life = 0; // Set life to 0 to end the game
        return; // Exit the function
    }
    
}

int ss1_l1(int *life){//question 1 for easy level 1
    pair W_size = get_cnl_wh();
    int round=1,level=1,high_si=2,time_limit=15,complite_syntax=0;
    const char *ans="int";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%sint %smain%s () {\n%s___%s i = %s0%s; %s// what should be placed here ?\n%swhile%s (i < %s10%s) {\n%sprintf (%s%c%cd%c,%s i);\ni++;\n}\n%sreturn %s0%s;\n\n}",c2(13),c2(10),c2(16),c2(13),c2(16),c2(2),c2(8),c2(6),c2(13),c2(16),c2(2),c2(16),c2(12),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(2),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,0/*blank x pos*/,10/*blank y pos*/,17/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34mint\033[0;33m because \033[1;37mi\033[0;33m is an integer variable, and \033[1;34\033[0;33mint is used to declare integer types in \033[1;35mC."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}
//start code samira
//for easy level
int ss2_l1(int *life){//question 2 for easy level 1
    pair W_size = get_cnl_wh();
    int round=2,level=1,high_si=2,time_limit=15,complite_syntax=0;
    const char *ans="int";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%sint %smain%s(){\n%s___%s age = %s25%s; %s// what should be placed here ?\n%sprintf%s(%sage:%c%cd%c%s, age);\n%sreturn %s0%s;\n\n}",c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(6),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,0/*blank x pos*/,10/*blank y pos*/,15/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34mint\033[0;33m because \033[1;37mi\033[0;33m is an integer variable, and \033[1;34\033[0;33mint is used to declare integer types in \033[1;35mC."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int ss3_l1(int *life){//question 3 for easy level 1
    pair W_size = get_cnl_wh();
    int round=3,level=1,high_si=2,time_limit=15,complite_syntax=0;
    const char *ans="value";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%sint %smain%s(){\n%sint%s _____ = %s100%s; %s// what should be placed here ?\n%sprintf%s(%s%cVariable Value:%cd%c%s, value);\n%sreturn %s0%s;\n\n}",c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(6),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,4/*blank x pos*/,10/*blank y pos*/,15/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34mvalue\033[0;33m because we are printing the variable named \033[1;37mvalue\033[0;33m with an integer variable."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int ss4_l2(int *life){//question 1 for easy level 2
    pair W_size = get_cnl_wh();
    int round=4,level=2,high_si=2,time_limit=15,complite_syntax=0;
    const char *ans="%";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%sint %smain%s(){\n%sint%s num;\n%sprintf%s(%s%cEnter a number:%c%s);\n%sscanf%s(%s%c_d%c%s,&num); %s// what should be placed here ?\n%sprintf%s(%s%cYou have entered: %cd%c%s,num);\n%sreturn %s0%s;\n\n}",c2(14),c2(10),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(6),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,6/*blank x pos*/,12/*blank y pos*/,17/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34m%\033[0;33m because \033[1;37m%d\033[0;33m is the right format to declare an inetger type value."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int ss5_l2(int *life){

}

int ss6_l3(int *life){//question 1 for easy level 3
    pair W_size = get_cnl_wh();
    int round=5,level=3,high_si=2,time_limit=15,complite_syntax=0;
    const char *ans="printf";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%sint %smain%s(){\n%schar%s name[%s50%s];\n%s______%s(%s%cEnter your name:%c%s); %s// what should be placed here ?\n%sscanf%s(%s%c%cs%c%s,&name);\n%sprintf%s(%s%cHello, %cs!%c%s,name);\n%sreturn %s0%s;\n\n}",c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(6),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,0/*blank x pos*/,11/*blank y pos*/,17/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34mprintf\033[0;33m because it is the right keyword to print the output in  \033[1;35mC."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int ss7_l3(int *life){

}
//for medium level

int ss8_l1(int *life){//question 1 for medium level 1
    pair W_size = get_cnl_wh();
    int round=1,level=1,high_si=2,time_limit=15,complite_syntax=0;
    const char *ans="for";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%sint %smain%s(){\n%s___%s(%sint %si = %s0%s; i < %s5%s; i++); %s// what should be placed here ?{\n%sprintf%s(%s%c%cd%c%s,i);\n}\n%sreturn %s0%s;\n\n}",c2(14),c2(10),c2(16),c2(13),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(6),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,0/*blank x pos*/,10/*blank y pos*/,16/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34mfor\033[0;33m because it is the right keyword to input a condition in \033[1;35mC."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}
int ss9_l1(int *life){

}

int ss10_l2(int *life){//question 1 for medium level 2
    pair W_size = get_cnl_wh();
    int round=1,level=2,high_si=2,time_limit=15,complite_syntax=0;
    const char *ans="a+b";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%s#%sinclude%s<stdio.h>\n%sint %sadd%s(%sint %sa, %sint %sb){\n%sreturn %s___; %s// what should be placed here ?\n%s}\n%sint %smain%s(){\n%sint %sresult = add(%s3%s,%s4%s);\n%sprintf%s(%s%cResult: %cd%c%s,result);\n%sreturn %s0%s;\n\n}",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(6),c2(16),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,7/*blank x pos*/,11/*blank y pos*/,19/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34m'a+b'\033[0;33m because it is the function of summation."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int ss11_l2(int *life){

}

int ss12_l3(int *life){//question 1 for medium level 3
    pair W_size = get_cnl_wh();
    int round=1,level=3,high_si=2,time_limit=15,complite_syntax=0;
    const char *ans="!=";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%s#%sinclude%s<stdio.h>\n%sint %smain%s(){\n%sint %sx = %s10%s, %sint %sy = %s20%s;\n%sif%s(x<y){\n%sif%s(x __ y){ %s// what should be placed here ?\n%sprintf%s(%s%cx is non-zero and less then y%c%s);\n }\n}\n%sreturn %s0%s;\n\n}",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(13),c2(16),c2(6),c2(13),c2(16),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[0],c2(16),c2(13),c2(14),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,5/*blank x pos*/,13/*blank y pos*/,20/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34m!=\033[0;33m for the condition in print function."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int ss13_l3(int *life){

}
//for hard level

int ss14_l1(int *life){//question 1 for medium level 1
    pair W_size = get_cnl_wh();
    int round=1,level=1,high_si=2,time_limit=15,complite_syntax=0;
    const char *ans="1,2,3,4,5";
    system("cls");
    dis_score("SYNTAX S-PRINT",round,score_s,high_si,level,*life);
     set_cnl_pos(0,7);
    animation("\033[1;33mFill the blanks with the correct syntax...\n\n",3);
    printf("%s#%sinclude%s<stdio.h>\n%sint %smain%s(){\n%sint %snumber[%s5%s] = {%s_%s_%s_%s_%s_%s_%s_%s_%s_%s}; %s// what should be placed here ?\n%sprintf%s(%s%cFirst:%cd%c%s,number[%s0%s]);\n%sreturn %s0%s;\n\n}",c2(16),c2(13),c2(11),c2(14),c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(6),c2(12),c2(16),c2(11),sm_ar[0],sm_ar[1],sm_ar[0],c2(16),c2(14),c2(16),c2(13),c2(14),c2(16));
   
   check_ans(round,high_si,level,time_limit,life,&complite_syntax,17/*blank x pos*/,11/*blank y pos*/,16/*data pos*/,ans,"\033[0;33mThe blank should be filled with \033[1;34m'1,2,3,4,5'\033[0;33m because the first 5 numbers are 1,2,3,4,5."); // Check the answer, here 1st is round, 2nd is high score, 3rd is level, 4th is time limit, 5th is life, 6th is complite_syntax, 7th is ans_pos, 8th is data_pos, 9th is ans, 10th is explanation
    return complite_syntax;
}

int ss15_l1(int *life){

}

int ss16_l2(int *life){

}

int ss17_l2(int *life){

}

int ss18_l3(int *life){

}

int ss19_l3(int *life){

}
//end code samira
int(*level_seasy[])() = {ss1_l1,ss2_l1,ss3_l1,ss4_l2,ss6_l3 /* other levels can be added here */}; // Array of function pointers for level 1 questions
int(*level_smedium[])() = {ss8_l1,ss10_l2,ss12_l3/* level 2 functions */}; // Array of function pointers for level 2 questions
int(*level_shard[])() = {ss14_l1/* level 3 functions */}; // Array of function pointers for level 3 questions

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
int life=3,complite_syntax=0;
for(int i=0;i<5&& back_s;i++){
   complite_syntax+= level_seasy[i](&life);
   if(life==0)break;
}
score_board_s(complite_syntax,life); // Call the score board function
back_s=1; // Reset back_s to 1 for the next game
}

void medium_s(){ // Function for medium syntax
pair W_size = get_cnl_wh();
set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+4);
animation("\033[1;32mStarting Medium Syntax...\n",2);
int life=3,complite_syntax=0;
for(int i=0;i<3&& back_s;i++){
   complite_syntax+= level_smedium[i](&life);
   if(life==0)break;
}
score_board_s(complite_syntax,life); // Call the score board function
back_s=1; // Reset back_s to 1 for the next game
}

void hard_s(){ // Function for hard syntax
pair W_size = get_cnl_wh();
set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+4);
animation("\033[1;32mStarting Hard Syntax...\n",2);
int life=3,complite_syntax=0;
for(int i=0;i<1&& back_s;i++){
  complite_syntax+= level_shard[i](&life);
   if(life==0)break;
}
score_board_s(complite_syntax,life); // Call the score board function
back_s=1; // Reset back_s to 1 for the next game
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