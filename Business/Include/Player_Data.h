class Dice{//optimized
    public:
    int color;
    draw(int shift){
        setcolor(BLACK);
        rectangle(617+shift,300,717+shift,400);
        setfillstyle(SOLID_FILL,color);
        floodfill(618+shift,301,BLACK);
        return 0;
    }
    drawLuck(int luck,int shift){
        setcolor(WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        switch (luck){
            case 1:
                circle(667+shift,350,20);
                floodfill(667+shift,350,WHITE);
            break;
            case 2:
                circle(687+shift,330,20);
                circle(647+shift,370,20);
                floodfill(687+shift,330,WHITE);
                floodfill(647+shift,370,WHITE);
            break;
            case 3:
                circle(644+shift,325,20);
                circle(690+shift,325,20);
                circle(667+shift,370,20);
                floodfill(642+shift,325,WHITE);
                floodfill(692+shift,325,WHITE);
                floodfill(667+shift,375,WHITE);
            break;
            case 4:
                circle(644+shift,325,20);
                circle(690+shift,325,20);
                circle(644+shift,370,20);
                circle(690+shift,370,20);
                floodfill(642+shift,325,WHITE);
                floodfill(692+shift,325,WHITE);
                floodfill(644+shift,370,WHITE);
                floodfill(690+shift,370,WHITE);
            break;
            case 5:
                circle(640+shift,320,15);
                circle(694+shift,320,15);
                circle(668+shift,350,15);
                circle(640+shift,380,15);
                circle(694+shift,380,15);
                floodfill(640+shift,320,WHITE);
                floodfill(694+shift,320,WHITE);
                floodfill(668+shift,350,WHITE);
                floodfill(640+shift,380,WHITE);
                floodfill(694+shift,380,WHITE);
            break;
            case 6:
                circle(635+shift,325,15);
                circle(667+shift,325,15);
                circle(702+shift,325,15);
                circle(635+shift,370,15);
                circle(667+shift,370,15);
                circle(702+shift,370,15);
                floodfill(635+shift,325,WHITE);
                floodfill(667+shift,325,WHITE);
                floodfill(702+shift,325,WHITE);
                floodfill(635+shift,370,WHITE);
                floodfill(667+shift,370,WHITE);
                floodfill(702+shift,370,WHITE);
            break;
        }
        return 0;
    }
};
class Token{//optimized
    public:
    int texture;
    int color;
    int radius;
    int position;
    draw(int x, int y){
        setcolor(color);
        circle(x,y,radius);
        setfillstyle(texture,color);
        floodfill(x,y,color);
        return 0;
    }

};
class Player{//optimized
    public:
        char name[PLAYER_NAME];
        int cash;
        int pno;
        Dice dice;
        Token token;
        void drawInformation(Player *ptr,int x){
            char CashStr[10];
            setbkcolor(INFOCOL);
            setcolor(BLACK);
            settextstyle(9,0,4);
            settextjustify(0,0);
            sprintf(CashStr,"$ %d",ptr->cash);
            outtextxy(20+x,670,(char*)"            ");
            outtextxy(20+x,670,CashStr);
        }
};

Player player1,player2;

int Move(int,Player*,Player*);
void Chance(Player *p1,Player *p2);
void Chest(Player *p1,Player *p2);
void Auction(Player *p1,Player *p2);
