#include<stdio.h>
#include<windows.h>

void c1(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

const char* c2(int color){
    const char *ar[] = {
        "\033[0m",                // Reset to default color
        "\033[0;30m",             // Black
        "\033[0;31m",             // Red
        "\033[0;32m",             // Green
        "\033[0;33m",             // Yellow
        "\033[0;34m",             // Blue
        "\033[0;35m",             // Magenta
        "\033[0;36m",             // Cyan
        "\033[0;37m",             // White
    
        "\033[1;30m",             // Bold Black
        "\033[1;31m",             // Bold Red
        "\033[1;32m",             // Bold Green
        "\033[1;33m",             // Bold Yellow
        "\033[1;34m",             // Bold Blue
        "\033[1;35m",             // Bold Magenta
        "\033[1;36m",             // Bold Cyan
        "\033[1;37m",             // Bold White
    
        "\033[40m",              // Black Background
        "\033[41m",              // Red Background
        "\033[42m",              // Green Background
        "\033[43m",              // Yellow Background
        "\033[44m",              // Blue Background
        "\033[45m",              // Magenta Background
        "\033[46m",              // Cyan Background
        "\033[47m",              // White Background
    };
    
    return ar[color];
}