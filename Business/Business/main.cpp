#include "Include\Headers.h"

using namespace std;

int main(){
    initGame();
    //strcpy(player1.name,"Player 1");
    //strcpy(player2.name,"Player 2");
    drawInput();
    versusWindow();
    drawGame();
    init_Grid();
    DrawHold();
    //---------------------------OTHER CALLS-------------------------------------
    //player1.token.color=4; //tmp
    //player2.token.color=2; //tmp
    //player1.dice.color=RED;player2.dice.color=GREEN; //tmp
    player1.token.draw(377,630);
    player2.token.draw(377,630);
    ActualDice();
    getch(); //ENDS GAME
    return 0;
}
