#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>

int score_b = 0;
void check_bug(int round,int high_si,int level,int time_limit,int *life,int *complite_syntax,int data_pos,int line,const char *ans,const char *explanation ){
 data_pos+=2;
    pair W_size = get_cnl_wh();
    c1(11);
    animation("\n\nEnter the line number where you found the problem: ",3); // Prompt the user to type their answer
    time_t start = time(NULL),time_diff; // Start the timer
    int in_line; // Variable to store the user's input
    char in_ans[200]; // Variable to store the user's input
    while(1){
     
      time_diff =time(NULL)-start; // Calculate the time difference
       set_cnl_pos(W_size.x-12,5);
       printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
       if(_kbhit()){ // Check if a key is pressed
         c1(10);
         set_cnl_pos(52,data_pos-1);
         scanf("%d",&in_line); // Read the line number from the user
         set_cnl_pos(W_size.x-12,5);
         time_diff =time(NULL)-start;
         printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
         
         if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("BUG HUNTER",round,score_b,high_si,level,*life);
               set_cnl_pos(0,data_pos);
                animation("\033[1;31mTime Up\033[0m",4);
      
        }
        else if(in_line!=line){ // Check if the user's answer is correct
              (*life)--; // Decrement the line number if the answer is incorrect
              dis_score("BUG HUNTER",round,score_b,high_si,level,*life); // Display the score
              set_cnl_pos(0,data_pos);
              animation("\033[1;31mIncorrect line Number!", 2); 
        }
        else { // If the answer is incorrect
             set_cnl_pos(0,data_pos+1);
             c1(11);
             animation("Input the corrected code line exactly as you would write it.", 3);
             c1(8);
             animation("\n[make sure to include spaces and formatting as shown in the question].", 2);
             data_pos+=3;
              set_cnl_pos(0,data_pos);
                c1(10);
              fgets(in_ans, sizeof(in_ans), stdin); // Read the corrected code line from the user
              set_cnl_pos(W_size.x-12,5);
              time_diff =time(NULL)-start;
              printf("%s Time: %02ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
                in_ans[strcspn(in_ans, "\n")] = 0; // Remove the newline character from the input
                 if(time_diff>=time_limit){ // Check if the time limit is exceeded
                ( *life)--;
                dis_score("BUG HUNTER",round,score_b,high_si,level,*life);
                set_cnl_pos(0,data_pos+2);
                animation("\033[1;31mTime Up\033[0m",4);
      
            }
                else if(strcmp(in_ans, ans) == 0) {
                score_b += 10; // Increment score by 10 for correct answer
                (*complite_syntax)++; // Increment the completed syntax count
                high_score_w(score_b,high_si);
                dis_score("BUG HUNTER",round,score_b,high_si,level,*life); // Display the score
                set_cnl_pos(0,data_pos+2);
                animation("\033[1;32mCorrect!", 2);
                }
                else {
                    (*life)--; // Decrement life if the answer is incorrect
                    dis_score("BUG HUNTER",round,score_b,high_si,level,*life); // Display the score
                    set_cnl_pos(0,data_pos+2);
                    animation("\033[1;31mIncorrect!", 2);
                }
                data_pos+=2;
        }
        break;
      }
      if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("SYNTAX S-PRINT",round,score_b,high_si,level,*life);
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
        c1(15);
        animation(explanation,4);
    }
    }
    set_cnl_pos(0,(W_size.y)-4);
    animation("\033[1;34mPress for next round...\033[0m",3);
    _getch();
    
}


int bh1_l1(int *life) {
    int round = 1, high_si = 3, level = 1, time_limit = 30, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  %s#%sinclude%s<stdio.h>\n%s2  %sint %smain%s () {\n%s3  %sint %sx = %s5%s;\n%s4  %sif %s(x = %s10%s) {\n%s5%s  printf%s(%s%cx is 10\\n%c%s);\n%s6%s  }\n%s7  %sreturn %s0%s;\n%s8  %s}",c2(8), c2(16), c2(13), c2(11), c2(8), c2(14), c2(10), c2(16), c2(8), c2(14), c2(16), c2(10), c2(16), c2(8), c2(13), c2(16), c2(10), c2(16), c2(8), c2(12), c2(16), c2(11),sm_ar[0],sm_ar[0],c2(16), c2(8), c2(16), c2(8),c2(13), c2(10),c2(16),c2(8),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 17 /*data pos*/, 4/*line*/, "if (x == 10) {", "The condition should use '==' for comparison, not '=' for assignment.");
    return complite_bug;
}
int bh2_l2(int *life) {
    int round = 1, high_si = 3, level = 2, time_limit = 30, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  #%sinclude%s<stdio.h>\n%s2  %sint %smain%s () {\n3  %schar %sage = %s25%s;\n4  %sprintf %s(%s\"Age: %%c\\n\"%s,age); \n5%s  return %s0%s;\n6  }",c2(16),c2(13), c2(11), c2(16), c2(14), c2(10), c2(16), c2(14), c2(16), c2(14), c2(16), c2(12), c2(16), c2(11), c2(16),c2(13),c2(14),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 15 /*data pos*/, 3/*line*/, "char age = '25';", "25 should stored in single quotation for character type data.");
    return complite_bug;
}
int bh3_l3(int *life) {
    int round = 1, high_si = 3, level = 3, time_limit = 30, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  #%sinclude%s<stdio.h>\n%s2  %sint %smain%s () {\n3  %sint %snumber;\n4  %sprintf %s(%s\"Enter a number: \"%s); \n5%s  scanf%s(%s\"%%d\"%s, number);\n6  %sprintf%s(%s\"You entered: %%d\\n\"%s, number);\n7  %sreturn %s0%s; \n8  }",c2(16),c2(13), c2(11), c2(16), c2(14), c2(10), c2(16), c2(14), c2(16), c2(12), c2(16), c2(11), c2(16), c2(12), c2(16),c2(11),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 17 /*data pos*/, 5/*line*/, "scanf(\"%%d\", &number);", "Missing & before number in scanf.");
    return complite_bug;
}
int bh4_l1(int *life) {
    int round = 1, high_si = 3, level = 1, time_limit = 30, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  #%sinclude%s<stdio.h>\n%s2  %sint %smain%s() {\n3  %sint %sx = %s10%s;\n4  %sif %s(x > %s10%s)\n5  %sprintf%s(%s\"x is greater than or equal to 10\\n\"%s);\n6  %selse if %s(x > %s5%s)\n7  %sprintf%s(%s\"x is greater than 5\\n\"%s);\n8  %sreturn %s0%s;\n9  } ",c2(16),c2(13), c2(11), c2(16), c2(14), c2(10), c2(16), c2(14), c2(16), c2(14), c2(16), c2(13), c2(16), c2(14), c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 18 /*data pos*/, 4/*line*/, "if (x >= 10)", "The condition x > 10 is incorrect for the message. It should be x >= 10.");
    return complite_bug;
}
int bh5_l2(int *life) {
    int round = 1, high_si = 3, level = 2, time_limit = 30, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  #%sinclude%s<stdio.h>\n%s2  %sint %smultiply%s (%sint %sa, %sint %sb) {\n3  %sreturn%s a + b;\n4  }\n5  %sint %smain%s() {\n6  %sint %sresult = multiply(%s3%s,%s 4%s);\n7  %sprintf%s(%s\"Result: %%d\\n\"%s, result); \n8%s  return %s0%s;\n9  }\n10  %sOutput: 12", c2(16),c2(13), c2(11), c2(16), c2(14), c2(10), c2(16), c2(14), c2(16), c2(14), c2(16), c2(13), c2(16), c2(14), c2(10),c2(16),c2(14),c2(16),c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16),c2(15));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 19 /*data pos*/, 3/*line*/, "return a * b;", "Should return a * b, not a + b.");
    return complite_bug;
}
int bh6_l3(int *life) {
    int round = 1, high_si = 3, level = 3, time_limit = 30, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  #%sinclude%s<stdio.h>\n%s2  %svoid %supdate%s(%sint %s*x) {\n3  *x = *x + %s1%s;\n4  }\n5  %sint %smain%s() {\n6  %sint %sa = %s5%s;\n7  update(a);\n8  %sprintf%s(%s\"%%d\\n\"%s, a);\n9  %sreturn %s0%s;\n10  }\n11  %sOutput: 6", c2(16),c2(13), c2(11), c2(16), c2(14), c2(10), c2(16), c2(14), c2(16), c2(14), c2(16), c2(14), c2(10), c2(16), c2(14),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16),c2(15));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 20 /*data pos*/, 7/*line*/, "update(&a);", "Passed a instead of &a, pointer not receiving address.");
    return complite_bug;
}
int bh7_l1(int *life) {
    int round = 1, high_si = 3, level = 1, time_limit = 30, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n\n", 3);
    printf("%s1  #%sinclude%s<stdio.h>\n%s2  #%sinclude %s<string.h>\n%s3  %sint %smain%s() { \n4  %schar %sstr[%s10%s];\n5  %sprintf%s(%s\"Enter a string: \"%s);\n6  %sscanf%s(%s\"%%9s\"%s, str);\n7  %sif %s(%sstrlen%s(str) = %s5%s)\n8  %sprintf%s(%s\"String length is 5\\n\"%s);\n9  %selse \n%s10  %sprintf%s(%s\"String length is not 5\\n\"%s);\n11  %sreturn %s0%s;\n12  }", c2(16),c2(13), c2(11), c2(16), c2(13), c2(11), c2(16), c2(14), c2(10), c2(16), c2(14), c2(16), c2(14), c2(16), c2(12),c2(16),c2(11),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(16),c2(12),c2(16),c2(14),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(16),c2(12),c2(16),c2(11),c2(16),c2(13),c2(14),c2(16));
    check_bug(round, high_si, level, time_limit, life, &complite_bug, 21 /*data pos*/, 7/*line*/, "if (strlen(str) == 5)", "The condition uses assignment (=) instead of equality check (==), so it always sets strlen(str) to 5 (which is invalid), causing unexpected behavior.");
    return complite_bug;
}

int (*level_beasy[])() = {bh1_l1,bh2_l2,bh3_l3 /*other levels can be added here */}; // Array of function pointers for level 1 questions
int (*level_bmedium[])() = {bh4_l1,bh5_l2,bh6_l3/*level 2 functions */}; // Array of function pointers for level 2 questions
int (*level_bhard[])() = {bh7_l1/*level 3 functions */}; // Array of function pointers for level 3 questions

void score_board_bug(int complite_bug, int life) { // Function to display the score board
    system("cls");
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 4, 0);
    printf("%sCODECRAFT\n\n", c2(15));
    set_cnl_pos((W_size.x / 2) - 7, (W_size.y / 2) - 4);
    if (life == 0) animation("\033[1;31mGAME OVER 0_0", 2);
    else        animation("\033[1;31mGAME COMPLETE", 2);
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) - 2);
    printf("%sYour current score: %02d%s", c2(15), score_b, c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) - 1);
    printf("%sYour High score: %02d%s", c2(15), high_score_r(3), c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2));
    printf("%sYour Complete Bug: %02d%s", c2(15), complite_bug, c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) + 2);
    animation("\033[1;34mPress any key for next...\033[0m", 3);
    _getch();

    score_b = 0;
}

void easy_b() { // Function for easy bug hunting
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Easy Bug Hunter...\n", 2);
    int life = 3, complite_bug=0;
    for (int i = 0; i < 3; i++) {
        complite_bug += level_beasy[i](&life);
        if (life == 0) break;
    }
    score_board_bug(complite_bug, life); // Call the score board function
}

void medium_b() { // Function for medium bug hunting
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Medium Bug Hunter...\n", 2);
    int life = 3, complite_bug=0;
    for (int i = 0; i < 3; i++) {
        complite_bug += level_bmedium[i](&life);
        if (life == 0) break;
    }
    score_board_bug(complite_bug, life); // Call the score board function
}

void hard_b() { // Function for hard bug hunting
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Hard Bug Hunter...\n", 2);
    int life = 3, complite_bug=0;
    for (int i = 0; i < 1; i++) {
        complite_bug += level_bhard[i](&life);
        if (life == 0) break;
    }
    score_board_bug(complite_bug, life); // Call the score board function
}

void bug_hunter() {
     system("cls");
    int choose=1,stp=0;
    char ch='1';
    while(1){
    dis_level(choose,stp++,"BUG HUNTER"); // Display the level selection menu
    ch=_getch();
    if((ch == 'w' || ch == 'W' || ch == 72) && choose > 1) choose--;
    else if((ch == 'x' || ch == 'X' || ch == 80) && choose < 4) choose++;
    else if(ch == 's' || ch == 'S' || ch == '\r'){
        if(choose == 1)easy_b();
        else if(choose == 2)medium_b();
        else if(choose == 3)hard_b();
        else if(choose == 4)break;
    }
    }
}