void initGame(){//optimized
    initwindow(1366,700);
    player1.pno=1;
    player2.pno=2;
    player1.cash=player2.cash=CASH;
    player1.token.position=player2.token.position=0;
    player1.token.texture=player2.token.texture=TOKTEX;
    player1.token.radius=20;
    player2.token.radius=18;
    player1.token.color=player2.token.color=0;

}

void drawGame(){//optimized
    graphdefaults();
    setbkcolor(GAME_WIN_COLOR);
    cleardevice();
    setcolor(0);
    for(int i=0;i<3;i++){
        rectangle(0+i,0+i,335-i,686-i);
        rectangle(1000+i,0+i,1355-i,686-i);
        line(0,580+i,335,580+i);
        line(1000,580+i,1355,580+i);
    }
    setfillstyle(SOLID_FILL,INFOCOL);
    floodfill(4,584,BLACK);
    floodfill(1004,584,BLACK);
    settextstyle(1,0,4);
    setcolor(RED);
    setbkcolor(WHITE);
    outtextxy(20,590,(char*)player1.name);
    outtextxy(1020,590,(char*)player2.name);
    graphdefaults();
    setbkcolor(GAME_WIN_COLOR);
    setcolor(0);
}

int Move(int luck,Player *p1,Player *p2){
    PlaySound("SFX\\token.BGA",NULL,SND_LOOP | SND_ASYNC);
    WhiteProp(1,p1->pno,p1->token.color);
    WhiteProp(4,p1->pno,p1->token.color);
    WhiteProp(10,p1->pno,p1->token.color);
    WhiteProp(18,p1->pno,p1->token.color);
    WhiteProp(23,p1->pno,p1->token.color);
    WhiteProp(1,p2->pno,p2->token.color);
    WhiteProp(4,p2->pno,p2->token.color);
    WhiteProp(10,p2->pno,p2->token.color);
    WhiteProp(18,p2->pno,p2->token.color);
    WhiteProp(23,p2->pno,p2->token.color);
    int oldcolor;
    for(int i=0;i<luck;i++){
        delay(300);
        oldcolor=prop[p1->token.position].prop_color;
        prop[p1->token.position].prop_color=0;
        prop[p1->token.position].draw();
        prop[p1->token.position].prop_color=oldcolor;
        prop[p1->token.position].draw();
        p1->token.position++;
        if(p1->token.position==28){
            p1->token.position=0;
        }
        p1->token.draw((prop[p1->token.position].x1+prop[p1->token.position].x2)/2,(prop[p1->token.position].y1+prop[p1->token.position].y2)/2);
        p2->token.draw((prop[p2->token.position].x1+prop[p2->token.position].x2)/2,(prop[p2->token.position].y1+prop[p2->token.position].y2)/2);
        if(p1->token.position==0){
            if(p1->pno==1){
                for(int i=0;i<p1top;i++){
                    if(prop[list1[i]].prop_status=='m'&&!LastChance(&player1,holdpos1,list1,p1top,i)){
                        prop[list1[i]].prop_status='u';
                        prop[list1[i]].drawFlags(GAME_WIN_COLOR);
                        Shift(&p1top,i,p1->pno);
                        i--;
                    }
                }
            }
            else{
                for(int i=0;i<p1top;i++){
                    if(prop[list2[i]].prop_status=='m'&&!LastChance(&player2,holdpos2,list2,p2top,i)){
                        prop[list2[i]].prop_status='u';
                        prop[list2[i]].drawFlags(GAME_WIN_COLOR);
                        Shift(&p2top,i,p1->pno);
                    }
                }
            }
            setbkcolor(GAME_WIN_COLOR);
            setcolor(BLACK);
            settextjustify(1,1);
            settextstyle(9,0,3);
            outtextxy(667,450,(char*)"Collect Dividend $200");
            modbal(p1->pno,200);
            setbkcolor(GAME_WIN_COLOR);
            setcolor(GAME_WIN_COLOR);
            settextjustify(1,1);
            settextstyle(9,0,3);
            outtextxy(667,450,(char*)"                                      ");
            PlaySound("SFX\\token.BGA",NULL,SND_LOOP | SND_ASYNC);
        }
    }
    PlaySound("SFX\\neigh.BGA",NULL,SND_ASYNC);
    delay(1000);
    PlaySound("SFX\\BG.BGA",NULL,SND_LOOP | SND_ASYNC);
    if(p1->cash<0){
        do{
            if(p1->pno==1)Mortage(&player1,holdpos1,list1,p1top);
            else Mortage(&player2,holdpos2,list2,p2top);
        }while(p1->cash<0);
    }
    return 0;
}

void ActualDice(){
    int Luck1,Luck2;int in;
    player1.drawInformation(&player1,0);
    player2.drawInformation(&player2,1000);

    while(true){
        PlaySound("SFX\\BG.BGA",NULL,SND_LOOP | SND_ASYNC);
        ////////////Game Beginning///////////////
        setbkcolor(GAME_WIN_COLOR);
        setcolor(BLACK);
        settextjustify(1,3);
        settextstyle(1,0,3);
        outtextxy(650,190,player1.name);
        while(true){
            in=getch();
            if(in==P1throw){
                outtextxy(650,190,(char*)"                    ");
                break;
            }
            else if(in==P1choose){
                outtextxy(650,190,(char*)"                    ");
                in=Option(1);
                if(in==1) Mortage(&player1,holdpos1,list1,p1top);
                else if(in==2)Redeem(&player1,holdpos1,list1,p1top);
                else if(in==3)Sell(&player1,holdpos1,list1,&p1top);
                else if(in==4)break;
            }
        };

         ///// Dice Function calling/////

        PlaySound("SFX\\dice.BGA",NULL,SND_ASYNC);
        delay(1500);
        srand(time(0));
        Luck1=rand()%6+1;
        player1.dice.draw(-60);
        player1.dice.drawLuck(Luck1,-60);
        Luck2=rand()%6+1;
        player1.dice.draw(60);
        player1.dice.drawLuck(Luck2,60);
        delay(100);

        Move(Luck1+Luck2,&player1,&player2);

        ///////Property Rules applyied Here///////////

        if ( prop[player1.token.position].Deal(1,&player1.cash,player1.token.position)  ){
                holdpos1[p1top].drawprop(p1top,1);
                p1top++;
        }

        ///////////////Turn changes////////////////


        setbkcolor(GAME_WIN_COLOR);
        setcolor(BLACK);
        settextjustify(1,3);
        settextstyle(1,0,3);
        outtextxy(650,190,player2.name);
        while(true){
            in=getch();
            if(in==P2throw){
                outtextxy(650,190,(char*)"                     ");
                break;
            }
            else if(in==P2choose){
                outtextxy(650,190,(char*)"                     ");
                in=Option(2);
                if(in==1)Mortage(&player2,holdpos2,list2,p2top);
                else if(in==2)Redeem(&player2,holdpos2,list2,p2top);
                else if(in==3)Sell(&player2,holdpos2,list2,&p2top);
                else if(in==4)break;
            }
        };

        ///// Dice Function calling/////

        PlaySound("SFX\\dice.BGA",NULL,SND_ASYNC);
        delay(1500);
        Luck1=rand()%6+1;
        player2.dice.draw(-60);
        player2.dice.drawLuck(Luck1,-60);
        Luck2=rand()%6+1;
        player2.dice.draw(60);
        player2.dice.drawLuck(Luck2,60);
        delay(100);

        Move(Luck1+Luck2,&player2,&player1);

        ///////Property Rules applyied Here///////////

        if ( prop[player2.token.position].Deal(2,&player2.cash,player2.token.position)  ){
                holdpos2[p2top].drawprop(p2top,2);
                p2top++;
       }
       PlaySound(NULL, NULL, 0);
    }
}


void DrawHold(){//optimized
    for(int j=0;j<5;j++){
        for(int i=3*j;i<3*(j+1);i++){
            holdpos1[i].x1=15+(i-3*j)*105;
            holdpos1[i].x2=110+(i-3*j)*105;
            holdpos1[i].y1=6+j*115;
            holdpos1[i].y2=116+j*115;
            holdpos1[i].draw();
            delay(TIMER);
        }
    }
    for(int j=0;j<5;j++){
        for(int i=3*j;i<3*(j+1);i++){
            holdpos2[i].x1=1020+(i-3*j)*108;
            holdpos2[i].x2=1115+(i-3*j)*108;
            holdpos2[i].y1=6+j*115;
            holdpos2[i].y2=116+j*115;
            holdpos2[i].draw();
            delay(TIMER);
        }
    }
}

void askToProp(int tp){//optimized
    char tmp[10];
    setcolor(BROWN);
    setfillstyle(SOLID_FILL,prop[tp].prop_color);
    rectangle(500,130,840,550);
    floodfill(501,131,BROWN);
    line(500,500,840,500);
    line(670,500,670,550);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(501,501,BROWN);
    setfillstyle(SOLID_FILL,RED);
    floodfill(671,501,BROWN);
    setbkcolor(prop[tp].prop_color);
    settextstyle(9,0,5);
    settextjustify(1,1);
    outtextxy(670,190,(char*)"             ");
    outtextxy(670,190,prop[tp].prop_name);
    sprintf(tmp,"$ %d",prop[tp].prop_rate/10);
    outtextxy(670,400,(char*)"             ");
    outtextxy(670,400,tmp);
    sprintf(tmp,"$ %d",prop[tp].prop_rate);
    outtextxy(670,470,(char*)"             ");
    outtextxy(670,470,tmp);
    settextstyle(8,0,3);
    setcolor(WHITE);
    setbkcolor(GREEN);
    outtextxy(585,530,(char*)"BUY");
    setbkcolor(RED);
    outtextxy(755,530,(char*)"DECLINE");
}

void modbal(int pno,int amt){//optimized
    PlaySound("SFX\\coin.BGA",NULL,SND_ASYNC);
    char AddStr[10];
    setbkcolor(INFOCOL);
    settextstyle(9,0,4);
    settextjustify(0,0);
    if(amt<0){
        sprintf(AddStr,"- %d",-amt);
        setcolor(RED);
    }
    else{
        sprintf(AddStr,"+ %d",amt);
        setcolor(GREEN);
    }
    if(pno==1){
        outtextxy(160,670,AddStr);
        player1.cash+=amt;
        delay(1000);
        outtextxy(160,670,(char*)"           ");
        player1.drawInformation(&player1,0);
    }
    else{
        outtextxy(1160,670,AddStr);
        player2.cash+=amt;
        delay(1000);
        outtextxy(1160,670,(char*)"           ");
        player2.drawInformation(&player2,1000);
    }
    PlaySound("SFX\\BG.BGA",NULL,SND_LOOP | SND_ASYNC);
}
