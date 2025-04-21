#include<stdio.h>
#include<stdlib.h>
#include<conio.h>  

#include "g_color.c"

void dis_wel(){
    system("cls");
    printf ("%sWelcome to CodeCraft!%s\n\n",c2(10),c2(0));
    printf ("%sA game to test your coding skills.%s\n",c2(4),c2(0));    
     
printf ("%sPress any key to continue...%s\n",c2(5),c2(0));
_getch();
}
void dis_menu(int choose,int stp) {
    system("cls");
    printf("%sMain Menu%s\n\n",c2(14),c2(0));
    printf("%s%sCode Quiz%s\n",c2(11),choose==1?"-> ":"   ",c2(0));
    printf("%s%sSyntax Sprint%s\n",c2(12),choose==2?"-> ":"   ",c2(0));
    printf("%s%sBug Hunter%s\n",c2(13),choose==3?"-> ":"   ",c2(0));
    printf("%s%sType Master%s\n",c2(14),choose==4?"-> ":"   ",c2(0));
    printf("%s%sMix Mode%s\n",c2(15),choose==5?"-> ":"   ",c2(0));
    printf("%s%sAbout%s\n",c2(16),choose==6?"-> ":"   ",c2(0));
    printf("%s%sExit%s\n",c2(10),choose==7?"-> ":"   ",c2(0));
    if(stp==0){
        c1(14);
         printf("\n\n Navigation arows written down blow\n\n");
         printf("\t\tW\n \t\t^\n\n\n");
         printf("\tA<\tS\t>D\n\n\n");
         printf("\t\tv\n\t\tX\n\n");
        c1(7);
    }

} 

void dis_exit(){
    system("cls");
    c1(10);
    printf("Thank you for playing CodeCraft!\n\n");
    c1(6);
    printf("Exiting the game. Goodbye!\n\n");
    c1(13);
    printf("About CodeCraft:\n");
    c1(15);
    printf("CodeCraft is a fun and  challenging console-based game designed to test your  vocabulary\n");
    printf("and  quick  thinking  skills. Built  using C programming  concepts, this  game  features\n");
    printf("multiple interactive modes, including word formation, syntax challenges, and bug-hunting\n");
    printf("puzzles. With  no graphics  or  images, it focuses  purely  on logic and user engagement,\n");
    printf("making it ideal for anyone who enjoys testing their cognitive abilities and learning new\nwords.\n\n"); 
    c1(13);
    printf("Creator :\n");
    c1(11);
    printf("Sayem Islam Leon\n");
    printf("Samira Ibrahim\n");
    printf("Motmayeen Billah\n");
    printf("Suborna Akter\n");
    printf("Shinzu\n");
    c1(7);
}

void dis_about(){
    system ("cls");
    printf("About CodeCraft:\n");
    c1(15);
    printf("CodeCraft is a fun and  challenging console-based game designed to test your  vocabulary\n");
    printf("and  quick  thinking  skills. Built  using C programming  concepts, this  game  features\n");
    printf("multiple interactive modes, including word formation, syntax challenges, and bug-hunting\n");
    printf("puzzles. With  no graphics  or  images, it focuses  purely  on logic and user engagement,\n");
    printf("making it ideal for anyone who enjoys testing their cognitive abilities and learning new\nwords.\n\n"); 
    c1(13);
    printf("Creator :\n");
    c1(11);
    printf("Sayem Islam Leon\n");
    printf("Samira Ibrahim\n");
    printf("Motmayeen Billah\n");
    printf("Suborna Akter\n");
    printf("Shinzu\n");
    c1(7);

    c1(3);
    printf("\nPress any key to return to the menu...\n");
    
    
_getch();
c1(7);
}
