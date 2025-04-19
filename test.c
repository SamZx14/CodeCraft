#include <stdio.h>
#include "g_color.c"  // Include your color-changing functions


    int main() {
        // Display foreground colors
        printf("Foreground Colors:\n");
        for (int i = 0; i <= 15; i++) {
            c1(i);
            printf("Color %d\n", i);  // Display color with index
        }

        // Display bold foreground colors
        printf("\nBold Foreground Colors:\n");
        for (int i = 0; i <= 15; i++) {
            c1(i + 10);  // Bold colors are typically in the range 10-15
            printf("Bold Color %d\n", i + 10);
        }

        // Display background colors
        printf("\nBackground Colors:\n");
        for (int i = 0; i <= 15; i++) {
            c1(40 + i);  // Background colors are in the range 40-47
            printf("Background Color %d\n", i);
        }

        // Reset to default color
        c1(0);
        printf("\nReset to default colors.\n");
        for(int i=1;i<=24;i++) printf("%scolor %d%s\n",c2(i),i,c2(0));


        return 0;
    }

