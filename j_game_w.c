#include<stdio.h>
#include<string.h>



void dis_level(int choose,int stp,const char *game)
{
    system("cls");
    pair W_size = get_cnl_wh();
    set_cnl_pos((W_size.x/2)-4,0);
    printf("%sCODECRAFT\n\n",c2(15));
    set_cnl_pos((W_size.x/2)-(strlen(game)/2),1);
    printf("%s%s%s\n",c2(11),game,c2(0));
    set_cnl_pos((W_size.x/2)-4,(W_size.y/2)-5);
    if(stp==0) animation("\033[1;35mLevel Menu\n\n",2);
    else printf("%sLevel Menu%s\n\n",c2(14),c2(0));
    set_cnl_pos((W_size.x/2)-3,(W_size.y/2)-3);
    printf("%s%sEasy%s\n",c2(11),choose==1?"-> ":" ",c2(0));
    set_cnl_pos((W_size.x/2)-3,(W_size.y/2)-2);
    printf("%s%sMedium%s\n",c2(12),choose==2?"-> ":" ",c2(0));
    set_cnl_pos((W_size.x/2)-3,(W_size.y/2)-1); 
    printf("%s%sHard%s\n",c2(13),choose==3?"-> ":" ",c2(0));
    set_cnl_pos((W_size.x/2)-3,(W_size.y/2));
    printf("%s%sBack%s\n",c2(10),choose==4?"-> ":" ",c2(0));
    set_cnl_pos((W_size.x/2)-10,(W_size.y/2)+3);
    if(stp==0) animation("\033[1;35mPlease choose a level... \n",2);
    c1(7);
}