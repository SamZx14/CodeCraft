#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#include "a1_choose_menu.c"
#include "b_code_quize.c"
#include "c_syntax_sprint.c"
#include "d_bug_hunter.c"
#include "e_type_master.c"
#include "f_mix_mode.c"

int main (){
    dis_wel();
    int choose=1,stp=0;
    char ch;
    while(1){
        
        dis_menu(choose,stp++);
        ch=_getch();
        if((ch=='w'|| ch=='W')&& choose>1) choose --;
        else if((ch=='x' || ch=='X')&& choose<7) choose ++;
        else if(ch=='\r'|| ch=='s' || ch=='s'){
            if(choose==1) code_quiz();
            else if(choose==2) syntax_sprint();
            else if(choose==3) bug_hunter();
            else if(choose==4) type_master();
            else if(choose==5) mix_mode();
            else if(choose==6) dis_about();
            else if(choose==7) {
                dis_exit();
                return 0;
            }
    }
    }
    return 0;
}