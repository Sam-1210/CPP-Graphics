#include "Include\Headers.h"

using namespace std;

int main(){
    initGame();
    HWND hWnd;
    hWnd = FindWindow(NULL, "Windows BGI");
    SendMessage((HWND) hWnd, WM_SETTEXT,0, (LPARAM)"Business Game");
    //PrimarySCR();
    PrimarySCR();
    drawInput();
    versusWindow();
    drawGame();
    init_Grid();
    DrawHold();
    player1.token.draw(377,630);
    player2.token.draw(377,630);
    ActualDice();
    return 0;
}
