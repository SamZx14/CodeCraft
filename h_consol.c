#include<stdio.h>
#include<windows.h>

typedef struct {
    int x;
    int y;
} pair;

pair get_cnl_wh() {
    CONSOLE_SCREEN_BUFFER_INFO cnli;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cnli);
    pair size;
    size.x = cnli.srWindow.Right - cnli.srWindow.Left + 1;
    size.y = cnli.srWindow.Bottom - cnli.srWindow.Top + 1;
    return size;
}

void set_cnl_pos(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}