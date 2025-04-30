#include <stdio.h> 

int ar[5]={0,0,0,0,0}; // Array to store high scores for 5 games
int high_score_r(int game){
    FILE *fp;
    fp = fopen("x_high_score.txt","r+");
    if(fp != NULL) {
        for(int i=0;i<5;i++){
            fscanf(fp,"%d\n",&ar[i]);
        }
        fclose(fp);
    }
    return ar[game-1];

}
void high_score_w(int score,int game){
    high_score_r(game);
    ar[game-1]=(score > ar[game-1])?score:ar[game-1];
    FILE *fp;
    fp = fopen("x_high_score.txt","r+");
    if (fp != NULL) {
        for(int i=0;i<5;i++){
            fprintf(fp,"%d\n",ar[i]);
        }
        fclose(fp);
    }
}


    int main() {
       int score = 20;
       high_score_w(score, 2); // 1 is the game number for code quiz
       int s= high_score_r(2); // 1 is the game number for code quiz
         printf("High Score: %d\n", s); // Print the high score
        return 0;
    }

