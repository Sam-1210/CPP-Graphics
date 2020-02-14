void casino(Player*);
class Property{
public:
    char prop_name[20];
    int prop_rate;
    int prop_color;
    int texture;
    int bkcolor;
    int multiplier;
    Flags flag1,flag2,flag3;
    char prop_status;
    int x1,x2,y1,y2;
    drawFlags(int pcolor){//optimized
        setcolor(pcolor);
        setfillstyle(SOLID_FILL,pcolor);
        circle(flag1.x,flag1.y,8);
        floodfill(flag1.x,flag1.y,pcolor);
        if(multiplier>1){
                circle(flag2.x,flag2.y,8);
                floodfill(flag2.x,flag2.y,pcolor);
        }
        if(multiplier>2){
                circle(flag3.x,flag3.y,8);
                floodfill(flag3.x,flag3.y,pcolor);
        }
        return 0;
    }
    draw(){//optimized
        char rate[5];
        graphdefaults();
        setbkcolor(bkcolor);
        setcolor(BROWN);
        rectangle(x1,y1,x2,y2);
        setfillstyle(texture,prop_color);
        floodfill(x1+1,y1+1,BROWN);
        setbkcolor(prop_color);
        settextjustify(1,3);
        if(prop_rate){
            setcolor(BLACK);
            settextstyle(2,0,5);
            outtextxy((x1+x2)/2,y1+5,prop_name);
            settextstyle(8,0,2);
            sprintf(rate,"$%d",prop_rate);
            outtextxy((x1+x2)/2,y2-25,rate);
        }
        else{
            setcolor(WHITE);
            settextstyle(8,0,1);
            outtextxy((x1+x2)/2,(y1+y2)/2-10,prop_name);
        }
        return 0;
    }
    Deal(int pno,int *pcash,int propno){
        char in,tmp[15];
        if(propno==21){//jail Optimized
            PlaySound("SFX\\siren.BGA",NULL,SND_ASYNC);
            setbkcolor(GAME_WIN_COLOR);
            setcolor(BLACK);
            settextjustify(1,1);
            settextstyle(9,0,3);
            outtextxy(667,450,(char*)"Jail Fine");
            delay(1000);
            modbal(pno,-50);
            setbkcolor(GAME_WIN_COLOR);
            settextjustify(1,1);
            settextstyle(9,0,3);
            outtextxy(667,450,(char*)"                         ");
        }
        else if(propno==5||propno==17){//chance Optimized
            if(pno==1)
                Chance(&player1,&player2);
            else
                Chance(&player2,&player1);
        }
        else if(propno==25){//chest Optimized
            if(pno==1)
                Chest(&player1,&player2);
            else
                Chest(&player2,&player1);
        }
        else if(propno==7){//auction Optimized
            if(pno==1)
                Auction(&player1,&player2);
            else
                Auction(&player2,&player1);
        }
        else if(propno==14){//casino Optimized
            setbkcolor(GAME_WIN_COLOR);
            setcolor(BLACK);
            settextjustify(1,1);
            settextstyle(9,0,3);
            outtextxy(667,450,(char*)"PLAY A GAME $20?");
            do{
            in=getch();
            }while(!(pno==1&&(in==P1YES||in==P1NO))&&!(pno==2&&(in==P2YES||in==P2NO)));
            if(PlayerSwitch(pno,in)==1){
                modbal(pno,-20);
                casino(&player1);
            }
            else if(PlayerSwitch(pno,in)==2){
                modbal(pno,-20);
                casino(&player2);
            }
            setbkcolor(GAME_WIN_COLOR);
            settextjustify(1,1);
            settextstyle(9,0,3);
            outtextxy(667,450,(char*)"                                  ");
        }
        if(prop_status=='u'&&prop_rate){//buy property      optimized
            if(*pcash<prop_rate){
                setbkcolor(GAME_WIN_COLOR);
                setcolor(RED);
                settextjustify(1,1);
                settextstyle(9,0,3);
                outtextxy(667,450,(char*)"Insufficient Balance!!");
                delay(1000);
                setcolor(GAME_WIN_COLOR);
                outtextxy(667,450,(char*)"                                               ");
                return false;
            }
            delay(1000);
            askToProp(propno);
            do{
                in=getch();
            }while(!(pno==1&&(in==P1YES||in==P1NO))&&!(pno==2&&(in==P2YES||in==P2NO)));
            if(PlayerSwitch(pno,in)==1){
                drawFlags(player1.token.color);
                prop_status=(char)pno;
                modbal(1,-prop_rate);
                list1[p1top]=propno;
                atpclean();
                if(BankEmpty()){
                    Decide_Winner();
                }
                return true;
            }
            else if(PlayerSwitch(pno,in)==2){
                drawFlags(player2.token.color);
                prop_status=(char)pno;
                modbal(2,-prop_rate);
                list2[p2top]=propno;
                atpclean();
                if(BankEmpty()){
                    Decide_Winner();
                }
                return true;
            }
            atpclean();
            return false;
        }
        else if(prop_status!='u'&&prop_status!='m'&&prop_status!=(char)pno){//rent   optimized
            setbkcolor(GAME_WIN_COLOR);
            setcolor(BLACK);
            settextjustify(1,1);
            settextstyle(9,0,3);
            sprintf(tmp,"Rent: $%d",(prop_rate/10)*multiplier);
            outtextxy(667,450,tmp);
            modbal(pno,-(prop_rate/10)*multiplier);
            if(pno==2) modbal(1,(prop_rate/10)*multiplier);
            else modbal(2,(prop_rate/10)*multiplier);
            setbkcolor(GAME_WIN_COLOR);
            settextjustify(1,1);
            settextstyle(9,0,3);
            outtextxy(667,450,(char*)"                                  ");
        }
        else if(prop_status==(char)pno&&*pcash>=prop_rate/2&&multiplier==1&&prop_color!=WHITE&&ColorComplete(pno,prop_color)){//capitalize    optimized
            setbkcolor(GAME_WIN_COLOR);
            setcolor(BLACK);
            settextjustify(1,1);
            settextstyle(9,0,3);
            outtextxy(667,450,(char*)"Want To Capitalize");
            sprintf(tmp,"$%d",prop_rate/2);
            outtextxy(667,480,tmp);
            do{
            in=getch();
            }while(!(pno==1&&(in==P1YES||in==P1NO))&&!(pno==2&&(in==P2YES||in==P2NO)));
            if(PlayerSwitch(pno,in)==1){
                ++multiplier;
                drawFlags(player1.token.color);
                modbal(1,-prop_rate/2);
            }
            else if(PlayerSwitch(pno,in)==2){
                ++multiplier;
                drawFlags(player2.token.color);
                modbal(2,-prop_rate/2);
            }
            setbkcolor(GAME_WIN_COLOR);
            settextjustify(1,1);
            settextstyle(9,0,3);
            outtextxy(667,450,(char*)"                                  ");
            outtextxy(667,480,(char*)"                         ");
        }
        return false;
    }
};
Property prop[28];

class PropHolder{//optimized
    public:
    int x1,x2,y1,y2;
    draw(){
        setbkcolor(GAME_WIN_COLOR);
        setcolor(LIGHTGRAY);
        rectangle(x1,y1,x2,y2);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(x1+1,y1+1,LIGHTGRAY);
        setcolor(BLACK);
        rectangle(x1,y1,x2,y2);
        setfillstyle(XHATCH_FILL,BROWN);
        floodfill(x1+1,y1+1,BLACK);
        return 0;
    }
    drawprop(int i,int player){
        char tmp[10];
        setcolor(BLACK);
        switch(player){
            case 1: setbkcolor(prop[list1[i]].prop_color);
                    setfillstyle(SOLID_FILL,prop[list1[i]].prop_color);
                    floodfill(x1+1,y1+1,BLACK);
                    settextjustify(1,3);
                    settextstyle(8,0,1);
                    outtextxy((x1+x2)/2,y1+8,(char*)"       ");
                    outtextxy((x1+x2)/2,y1+8,prop[list1[i]].prop_name);
                    sprintf(tmp,"$ %d",prop[list1[i]].prop_rate/10);
                    outtextxy((x1+x2)/2,y2-45,(char*)"       ");
                    outtextxy((x1+x2)/2,y2-45,tmp);
                    sprintf(tmp,"$ %d",prop[list1[i]].prop_rate);
                    outtextxy((x1+x2)/2,y2-25,(char*)"       ");
                    outtextxy((x1+x2)/2,y2-25,tmp);
                    if(prop[list1[i]].prop_status=='m'){
                        setcolor(5);
                        line(x1,y1,x2,y2);
                        line(x2,y1,x1,y2);
                    }
            break;
            case 2: setbkcolor(prop[list2[i]].prop_color);
                    setfillstyle(SOLID_FILL,prop[list2[i]].prop_color);
                    floodfill(x1+1,y1+1,BLACK);
                    settextjustify(1,3);
                    settextstyle(8,0,1);
                    outtextxy((x1+x2)/2,y1+8,(char*)"       ");
                    outtextxy((x1+x2)/2,y1+8,prop[list2[i]].prop_name);
                    sprintf(tmp,"$ %d",prop[list2[i]].prop_rate/10);
                    outtextxy((x1+x2)/2,y2-45,(char*)"       ");
                    outtextxy((x1+x2)/2,y2-45,tmp);
                    sprintf(tmp,"$ %d",prop[list2[i]].prop_rate);
                    outtextxy((x1+x2)/2,y2-25,(char*)"       ");
                    outtextxy((x1+x2)/2,y2-25,tmp);
                    if(prop[list2[i]].prop_status=='m'){
                        setcolor(5);
                        line(x1,y1,x2,y2);
                        line(x2,y1,x1,y2);
                    }
            break;
        }
        return 0;
    }
} holdpos1[15],holdpos2[15];

int Offer(Player*,PropHolder[],int[],int*);
