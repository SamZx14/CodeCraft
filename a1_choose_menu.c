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
}

void dis_about(){
system ("cls");
// write the about code here
    


c1(3);
printf("\nPress any key to return to the menu...\n");
_getch();
c1(7);
}
