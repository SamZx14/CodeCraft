#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>

int score_t=0;

void check_ans_type(){ // Function to check the answer
    // Implement the logic to check the answer for Type Master game

}

int tm1_l1(int *life){
    int round = 1, high_si = 4, level = 1, time_limit = 20, complite_type =0;
    char ans[30]="";
    system("cls");
    dis_score("TYPE MASTER", round, score_t, high_si, level, *life);
    set_cnl_pos(0, 7);
    animation("\033[1;32mType the given text as fast as you can!\n", 3);

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
    set_cnl_pos((W_size.x / 2) - 7, (W_size.y / 2) - 4);
    if (life == 0) animation("\033[1;31mGAME OVER 0_0", 2);
    else        animation("\033[1;31mGAME COMPLITE", 2);
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) - 2);
    printf("%sYour current score: %02d%s", c2(15), score_t, c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) - 1);
    printf("%sYour High score: %02d%s", c2(15), high_score_r(4), c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2));
    printf("%sYour Complite Type: %02d%s", c2(15), complite_type, c2(0));
    set_cnl_pos((W_size.x / 2) - 12, (W_size.y / 2) + 2);
    animation("\033[1;34mPress any key for next...\033[0m", 3);
    _getch();

    score_t = 0;
}

void easy_t() { // Function for easy type master
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Easy Type Master...\n", 2);
    int life = 3, complite_type;
    for (int i = 0; i < 1; i++) {
        complite_type = level_teasy[i](&life);
        if (life == 0) break;
    }
    score_board_t(complite_type, life); // Call the score board function
}

void medium_t() { // Function for medium type master
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Medium Type Master...\n", 2);
    int life = 3, complite_type;
    for (int i = 0; i < 1; i++) {
        complite_type = level_tmedium[i](&life);
        if (life == 0) break;
    }
    score_board_t(complite_type, life); // Call the score board function
}

void hard_t() { // Function for hard type master
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x / 2) - 10, (W_size.y / 2) + 4);
    animation("\033[1;32mStarting Hard Type Master...\n", 2);
    int life = 3, complite_type;
    for (int i = 0; i < 1; i++) {
        complite_type = level_thard[i](&life);
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