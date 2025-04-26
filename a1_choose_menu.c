#include<stdio.h>
#include<stdlib.h>
#include<conio.h>  

#include "g_color.c"

void dis_nvg(int *stp){
    if(*stp==0){
        *stp++;
        c1(14);
         animation("\n\n Navigation arows written down blow\n\n",2);
         printf("\t\tW\n \t\t^\n\n\n");
         printf("\tA<\tS\t>D\n\n\n");
         printf("\t\tv\n\t\tX\n\n");
        c1(7);
    }

}
void dis_wel(){
    system("cls");
    
    animation("\033[1;31mWelcome to CodeCraft!\n\n",1);
    
    animation("\033[0;33mA game to test your coding skills.\n",2);    
     
    animation ("\033[0;34mPress any key to continue...\n",2);
_getch();
}
void dis_menu(int choose,int stp) {
    system("cls");
    if(stp==0) animation("\033[1;35mMain Menu\n\n",2);
    else printf("%sMain Menu%s\n\n",c2(14),c2(0));
    
    
    
    printf("%s%sCode Quiz%s\n",c2(11),choose==1?"-> ":"   ",c2(0));
    printf("%s%sSyntax Sprint%s\n",c2(12),choose==2?"-> ":"   ",c2(0));
    printf("%s%sBug Hunter%s\n",c2(13),choose==3?"-> ":"   ",c2(0));
    printf("%s%sType Master%s\n",c2(14),choose==4?"-> ":"   ",c2(0));
    printf("%s%sMix Mode%s\n",c2(15),choose==5?"-> ":"   ",c2(0));
    printf("%s%sAbout%s\n",c2(16),choose==6?"-> ":"   ",c2(0));
    printf("%s%sExit%s\n",c2(10),choose==7?"-> ":"   ",c2(0));
    dis_nvg(&stp);
} 

void dis_exit(){
    system("cls");
// write the exit code here
//start code -SAMIRA
animation("\033[1;33mTHANK YOU FOR PLAYING CODECRAFT !",2);
printf("%s  (^-^)\n\n\n",c2(10));

animation("\033[0;34m=>> Did You Enjoy The Coding Adventure ?",3);
printf("%s  (*o*)\n\n",c2(10));
animation("\033[1;37mYou've just experienced the amazing world of ",3);

animation("\033[1;34mCODECRAFT ",3);

animation("\033[1;37mby being our amazing ",3);

animation("\033[0;34mCODECRAFTER ",3);

animation("\033[1;37mwhile having a blast of enjoyment ! \n",3);

animation("\033[1;37mWe hope you leveled up your programming prowess by aced ",3);

animation("\033[1;31mCODE QUIZ ",3);

animation("\033[1;37m, raced against logic in ",3);

animation("\033[1;31mSYNTAX SPRINT ",3);

animation("\033[1;37m, hunted down bugs wildly in ",3);

animation("\033[1;31mBUG HUNTER  ",3);

animation("\033[1;37mor typed like a pro in ",3);

animation("\033[1;31mTYPE MASTER ",3);

animation("\033[1;37m.\n\n\n",3);

animation("\033[1;32m=>> WHAT'S NEXT ?",3);
printf("%s  (*-*)\n\n",c2(10));

animation("\033[0;36mChallenge Yourself Again ",5);
printf("%s---> Try %sMIX MODE %sfor the ultimate test ...!\n",c2(8),c2(6),c2(8));

animation("\033[0;36mBeat Your High Score ",5);
printf("%s---> Can you conquer %sHARD %smode ...?\n",c2(8),c2(6),c2(8));

animation("\033[0;36mShare with Friends ",5);
printf("%s---> Who's the %sBEST CODER %sin your Squad ...?\n\n",c2(8),c2(6),c2(8));

animation("\033[1;35m||> DARE IF YOU CAN DO BETTER NEXT TIME ... DARE IF YOU WANT TO PROVE YOURSELF THE BEST CODECRAFTER EVER  ...<||",4);
printf("%s  (>-*)\n\n",c2(10));

animation("\033[1;36m=>>Farewell, Future Code Master !",2);
printf("%s  (>-<)\n\n",c2(10));

animation("\033[1;37mThe best debugger is a good night's sleep ... or another round of ",2);
printf("%sCODECRAFT !\n\n",c2(13));

animation("\033[1;33m=>>Made With :\n\n",3.5);

animation("\033[1;31m*THE C GURU*",3);
printf("%s  (*+*)\n\n",c2(10));

animation("\033[1;34m# Keep Coding... Keep Crafting...#\n\n",1.5);
//end code -SAMIRA

c1(5);
printf("\nPress any key to return to the menu...\n");
_getch();
c1(7);
}

void dis_about(){
system ("cls");
// write the about code here
//start code -SAMIRA
animation("\033[1;34mABOUT CODECRAFT :\n\n\n",2);




c1(3);
printf("\nPress any key to return to the menu...\n");
_getch();
c1(7);
}
