#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>

int score_b = 0;
void check_bug(){

}

int bh1_l1(int *life) {
    int round = 1, high_si = 3, level = 1, time_limit = 20, complite_bug =0;
    char ans[30]="";
    system("cls");
    dis_score("BUG HUNTER", round, score_b, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mFind the bug in the code, fix it!\n", 3);

    return complite_bug;
}

int (*level_beasy[])() = {bh1_l1, /* other levels can be added here */}; // Array of function pointers for level 1 questions
int (*level_bmedium[])() = {/* level 2 functions */}; // Array of function pointers for level 2 questions
int (*level_bhard[])() = {/* level 3 functions */}; // Array of function pointers for level 3 questions

void score_board_bug(int complite_bug, int life) { // Function to display the score board
    system("cls");
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 4, 0);
    printf("%sCODECRAFT\n\n", c2(15));
    set_cnl_pos((W_size.x / 2) - 7, (W_size.y / 2) - 4);
    if (life == 0) animation("\033[1;31mGAME OVER 0_0", 2);
    else        animation("\033[1;31mGAME COMPLITE", 2);
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) - 2);
    printf("%sYour current score: %02d%s", c2(15), score_b, c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) - 1);
    printf("%sYour High score: %02d%s", c2(15), high_score_r(3), c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2));
    printf("%sYour Complite Bug: %02d%s", c2(15), complite_bug, c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) + 2);
    animation("\033[1;34mPress any key for next...\033[0m", 3);
    _getch();

    score_b = 0;
}

void easy_b() { // Function for easy bug hunting
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Easy Bug Hunter...\n", 2);
    int life = 3, complite_bug;
    for (int i = 0; i < 1; i++) {
        complite_bug = level_beasy[i](&life);
        if (life == 0) break;
    }
    score_board_bug(complite_bug, life); // Call the score board function
}

void medium_b() { // Function for medium bug hunting
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Medium Bug Hunter...\n", 2);
    int life = 3, complite_bug;
    for (int i = 0; i < 1; i++) {
        complite_bug = level_bmedium[i](&life);
        if (life == 0) break;
    }
    score_board_bug(complite_bug, life); // Call the score board function
}

void hard_b() { // Function for hard bug hunting
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Hard Bug Hunter...\n", 2);
    int life = 3, complite_bug;
    for (int i = 0; i < 1; i++) {
        complite_bug = level_bhard[i](&life);
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