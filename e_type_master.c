#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
double avg_speed=0.0,
       avg_right=0.0,
       avg_wrong=0.0,
       avg_accuracy=0.0;
int score_t=0;

void check_ans_type(int round, int high_si,int level,int time_limit,int *life,int *comlite_type,int line,char *ans[]){  // Function to check the answer
   
    // Implement the logic to check the answer for Type Master game
    pair W_size = get_cnl_wh();
    c1(11);
    animation("\n\033[1;32mType the given text as fast as you can!\n", 3);
    c1(8);
    animation("[make sure to include spaces and formatting as shown in the question].\n", 3);
    double speed = 0.0, right = 0.0, wrong = 0.0, accuracy = 0.0,total_char=0,time_al,total_in_char=0; 
    char input[256];
    time_t start = time(NULL),time_diff; // Start the timer
    int line1=line;
    while(line1){
        time_diff = time(NULL) - start; // Calculate the time difference
         set_cnl_pos(W_size.x-12,5);
         printf("%s Time: %03ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
        
        if(_kbhit()){
            for(;line1>0;line1--){
                 set_cnl_pos(0, 10+line+(line-line1));
                 c1(15-(line-line1));
                 fgets(input, sizeof(input), stdin); // Read the input from the user
                 total_in_char+=strlen(input);
                 time_diff = time(NULL) - start; // Calculate the time difference
                 set_cnl_pos(W_size.x-12,5);
                 printf("%s Time: %03ds%s",c2(15),time_limit-time_diff,c2(0)); // the timer
                 time_al=time_diff;
         if(time_diff>=time_limit){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("TYPE MASTER",round,score_t,high_si,level,*life);
               set_cnl_pos(0, 10+line+(line-line1)+1);
                animation("\033[1;31mTime Up\033[0m",4);
                line1=0;
                break;
      
        }
                 input[strcspn(input, "\n")] = 0; // Remove the newline character from the input
            
                for(int j= 0;j<strlen(ans[line-line1]);j++){
                    if(ans[line-line1][j] != input[j]) wrong++;
                    else right++;
                    total_char++;
                }
              }
            }
             if(line1&&(time_diff>=time_limit)){ // Check if the time limit is exceeded
               ( *life)--;
               dis_score("TYPE MASTER",round,score_t,high_si,level,*life);
               set_cnl_pos(0, 10+line+(line-line1)+1);
                animation("\033[1;31mTime Up\033[0m",4);
                line1=0;
        }
    }
    if(time_diff<time_limit){
        speed= total_in_char/ (time_al/60);
        if(right == 0) speed = 0;// Avoid division by zero
       
        accuracy = (right / total_char) * 100; // Calculate accuracy
         score_t +=( accuracy/10); // Update the score based on accuracy
         high_score_w(score_t,high_si);
                dis_score("TYPE MASTER",round,score_t,high_si,level,*life); // Display the score
        (*comlite_type)++;
        system("cls");
         set_cnl_pos((W_size.x / 2) - 4, 0);
    printf("%sCODECRAFT", c2(15));
      set_cnl_pos((W_size.x / 2) - 5, 1);
    printf("%sTYPE MASTER", c2(14));

    set_cnl_pos((W_size.x / 2) - 5, (W_size.y / 2) - 4);
    animation("\033[1;31mDash Board", 2);
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 2);
    printf("%sYour current score: %02d%s", c2(13), score_t, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 1);
    printf("%sYour right input: %03d%s", c2(13), (int)right, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) );
    printf("%sYour wrong input: %03d%s", c2(13), (int)wrong, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2)+1);
    printf("%sYour typing speed: %04.2lf c/m%s", c2(13),speed, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) + 2);
        printf("%sYour accuracy: %04.2lf%%\n%s", c2(13), accuracy, c2(0));

    avg_right+=right;
    avg_wrong+=wrong;
    avg_speed+=speed;
    avg_accuracy+= accuracy;

    }
    set_cnl_pos((W_size.x / 2) - 11, W_size.y  -2);
     animation("\033[1;34mPress any key for next...\033[0m", 3);
    _getch();
    
}


int tm1_l1(int *life){
    pair W_size = get_cnl_wh();
    int round = 1, high_si = 4, level = 1, time_limit = 80, complite_type =0,line=5;
    char *ans[] = {"#include <stdio.h>", "int main() {", "printf(\"Hello, World!\\n\");", "return 0;", "}"};
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
     printf("%s#%sinclude %s<stdio.h>\n%sint %smain%s() {\n%sprintf%s(%s\"Hello, World!\\n\"%s);\n%sreturn %s0%s;\n}\n", c2(16), c2(13), c2(11), c2(14), c2(10), c2(16), c2(12), c2(16), c2(11), c2(16), c2(13),c2(10), c2(16));
     check_ans_type(round, high_si, level, time_limit, life, &complite_type, line, ans);
     
    return complite_type;

}

int (*level_teasy[])() = {tm1_l1, /* other levels can be added here */}; // Array of function pointers for level 1 questions
int (*level_tmedium[])() = {/* level 2 functions */}; // Array of function pointers for level 2 questions
int (*level_thard[])() = {/* level 3 functions */}; // Array of function pointers for level 3 questions

void score_board_t(int complite_type, int life) { // Function to display the score board
    system("cls");
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 4, 0);
    printf("%sCODECRAFT\n\n", c2(15));
    set_cnl_pos((W_size.x / 2) - 7, (W_size.y / 2) - 6);
    if (life == 0) animation("\033[1;31mGAME OVER 0_0", 2);
    else        animation("\033[1;31mGAME COMPLETE", 2);
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 4);
    printf("%sYour right input: %03d%s", c2(14),(complite_type==0)? 0: ((int)avg_right/complite_type), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) - 3);
    printf("%sYour wrong input: %03d%s", c2(14), (complite_type==0)? 0:((int)avg_wrong/complite_type), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2)-2);
    printf("%sYour typing speed: %lf w/m%s", c2(14),(complite_type==0)? 0: (avg_speed/complite_type), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) -1);
    printf("%sYour accuracy: %lf%%\n%s", c2(14),(complite_type==0)? 0:( avg_accuracy/complite_type), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) +1);
    printf("%sYour current score: %02d%s", c2(15), score_t, c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) +2);
    printf("%sYour High score: %02d%s", c2(15), high_score_r(4), c2(0));
    set_cnl_pos((W_size.x / 2) - 11, (W_size.y / 2) +3);
    printf("%sYour Complete Type: %02d%s", c2(15), complite_type, c2(0));
     set_cnl_pos((W_size.x / 2) - 11, W_size.y -2);
    animation("\033[1;34mPress any key for next...\033[0m", 3);
    _getch();

    score_t = 0;
}

void easy_t() { // Function for easy type master
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Easy Type Master...\n", 2);
    int life = 3, complite_type=0;
    for (int i = 0; i < 1; i++) {
        complite_type += level_teasy[i](&life);
        if (life == 0) break;
    }
    score_board_t(complite_type, life); // Call the score board function
}

void medium_t() { // Function for medium type master
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Medium Type Master...\n", 2);
    int life = 3, complite_type=0;
    for (int i = 0; i < 1; i++) {
        complite_type += level_tmedium[i](&life);
        if (life == 0) break;
    }
    score_board_t(complite_type, life); // Call the score board function
}

void hard_t() { // Function for hard type master
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Hard Type Master...\n", 2);
    int life = 3, complite_type=0;
    for (int i = 0; i < 1; i++) {
        complite_type += level_thard[i](&life);
        if (life == 0) break;
    }
    score_board_t(complite_type, life); // Call the score board function
}

void type_master() {
   system("cls");
    int choose = 1, stp = 0;
    char ch='1';
    while (1) {
        system("cls");
        dis_level(choose, stp++, "TYPE MASTER"); // Display the level menu
        ch = _getch();
        if ((ch == 'w' || ch == 'W' || ch == 72) && choose > 1) choose--;
        else if ((ch == 'x' || ch == 'X' || ch == 80) && choose < 4) choose++;
        else if (ch == '\r' || ch == 's' || ch == 's') {
            if (choose == 1) easy_t(); // Call the easy type master function
            else if (choose == 2) medium_t(); // Call the medium type master function
            else if (choose == 3) hard_t(); // Call the hard type master function
            else if (choose == 4) break;
        }
    }
}