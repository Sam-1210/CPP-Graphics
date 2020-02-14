void init_Grid(){//optimized
    prop[0].x1=337;
    prop[0].x2=417;
    prop[0].y1=590;
    prop[0].y2=670;
    strcpy(prop[0].prop_name,PropName[0]);
    prop[0].prop_rate=PropRate[0];
    prop[0].prop_color=PropColor[0];
    prop[0].texture=1;
    prop[0].prop_status='u';
    prop[0].multiplier=1;
    prop[0].draw();
    delay(TIMER);
    for(int i=1;i<8;i++){
        if(i==5){prop[i].texture=11;}
        else{prop[i].texture=1;}
        prop[i].x1=prop[i-1].x1+83;
        prop[i].x2=prop[i-1].x2+83;
        prop[i].y1=prop[0].y1;
        prop[i].y2=prop[0].y2;
        prop[i].prop_status='u';
        strcpy(prop[i].prop_name,PropName[i]);
        prop[i].prop_rate=PropRate[i];
        prop[i].prop_color=PropColor[i];
        prop[i].bkcolor=7;
        prop[i].multiplier=1;
        prop[i].flag1.x=prop[i].x1+20;
        prop[i].flag1.y=prop[i].y1-10;
        prop[i].flag2.x=prop[i].x1+40;
        prop[i].flag2.y=prop[i].y1-10;
        prop[i].flag3.x=prop[i].x1+60;
        prop[i].flag3.y=prop[i].y1-10;
        prop[i].draw();
        delay(TIMER);
    }
    for(int i=8;i<15;i++){
        prop[i].x1=prop[7].x1;
        prop[i].x2=prop[7].x2;
        prop[i].y1=prop[i-1].y1-83;
        prop[i].y2=prop[i-1].y2-83;
        prop[i].prop_status='u';
        strcpy(prop[i].prop_name,PropName[i]);
        prop[i].prop_rate=PropRate[i];
        prop[i].prop_color=PropColor[i];
        prop[i].bkcolor=7;
        prop[i].texture=1;
        prop[i].multiplier=1;
        prop[i].flag1.x=prop[i].x1-10;
        prop[i].flag1.y=prop[i].y1+20;
        prop[i].flag2.x=prop[i].x1-10;
        prop[i].flag2.y=prop[i].y1+40;
        prop[i].flag3.x=prop[i].x1-10;
        prop[i].flag3.y=prop[i].y1+60;
        prop[i].draw();
        delay(TIMER);
    }
    for(int i=15;i<22;i++){
        if(i==17){prop[i].texture=11;}
        else if(i==21){prop[i].texture=7;}
        else{prop[i].texture=1;}
        prop[i].x1=prop[i-1].x1-83;
        prop[i].x2=prop[i-1].x2-83;
        prop[i].y1=prop[14].y1;
        prop[i].y2=prop[14].y2;
        prop[i].prop_status='u';
        strcpy(prop[i].prop_name,PropName[i]);
        prop[i].prop_rate=PropRate[i];
        prop[i].prop_color=PropColor[i];
        prop[i].bkcolor=7;
        prop[i].multiplier=1;
        prop[i].flag1.x=prop[i].x1+20;
        prop[i].flag1.y=prop[i].y2+10;
        prop[i].flag2.x=prop[i].x1+40;
        prop[i].flag2.y=prop[i].y2+10;
        prop[i].flag3.x=prop[i].x1+60;
        prop[i].flag3.y=prop[i].y2+10;
        prop[i].draw();
        delay(TIMER);
    }
    for(int i=22;i<28;i++){
        if(i==25){prop[i].texture=11;}
        else{prop[i].texture=1;}
        prop[i].x1=prop[21].x1;
        prop[i].x2=prop[21].x2;
        prop[i].y1=prop[i-1].y1+83;
        prop[i].y2=prop[i-1].y2+83;
        prop[i].prop_status='u';
        strcpy(prop[i].prop_name,PropName[i]);
        prop[i].prop_rate=PropRate[i];
        prop[i].prop_color=PropColor[i];
        prop[i].bkcolor=7;
        prop[i].multiplier=1;
        prop[i].flag1.x=prop[i].x2+10;
        prop[i].flag1.y=prop[i].y1+20;
        prop[i].flag2.x=prop[i].x2+10;
        prop[i].flag2.y=prop[i].y1+40;
        prop[i].flag3.x=prop[i].x2+10;
        prop[i].flag3.y=prop[i].y1+60;
        prop[i].draw();
        delay(TIMER);
    }
    setbkcolor(GAME_WIN_COLOR);
}

int PlayerSwitch(int pno,char in){//optimized
    if(pno==1){
        if(in==P1YES) return 1;
        return 5;
    }
    if(pno==2){
        if(in==P2YES) return 2;
        return 5;
    }
    return 0;
}

void atpclean(){//optimized
    setbkcolor(GAME_WIN_COLOR);
    setcolor(GAME_WIN_COLOR);
    rectangle(499,129,841,551);
    setfillstyle(SOLID_FILL,GAME_WIN_COLOR);
    floodfill(500,130,GAME_WIN_COLOR);

}

void casino(Player *p){//optimized
    setbkcolor(GAME_WIN_COLOR);
    setcolor(GREEN);
    settextjustify(1,1);
    settextstyle(9,0,3);
    switch(rand()%20+1){
        case 1: outtextxy(667,450,(char*)"FIRST PRIZE!! $500");
                modbal(p->pno,500);
                break;
        case 2: outtextxy(667,450,(char*)"SECOND PRIZE!! $200");
                modbal(p->pno,200);
                break;
        case 3: outtextxy(667,450,(char*)"THIRD PRIZE!! $100");
                modbal(p->pno,100);
                break;
        case 4: outtextxy(667,450,(char*)"THIRD PRIZE!! $100");
                modbal(p->pno,100);
                break;
        case 5: outtextxy(667,450,(char*)"THIRD PRIZE!! $100");
                modbal(p->pno,100);
                break;
        case 6: outtextxy(667,450,(char*)"CONSOLATION PRIZE!! $50");
                modbal(p->pno,50);
                break;
        case 7: outtextxy(667,450,(char*)"CONSOLATION PRIZE!! $50");
                modbal(p->pno,50);
                break;
        case 8: outtextxy(667,450,(char*)"CONSOLATION PRIZE!! $50");
                modbal(p->pno,50);
                break;
        case 9: outtextxy(667,450,(char*)"CONSOLATION PRIZE!! $50");
                modbal(p->pno,50);
                break;
        case 10: outtextxy(667,450,(char*)"CONSOLATION PRIZE!! $50");
                modbal(p->pno,50);
                break;
        default:setcolor(BLUE);
                outtextxy(667,450,(char*)"BABAJI KA THULLU!!");
                delay(500);
                break;
    }
    setbkcolor(GAME_WIN_COLOR);
    settextjustify(1,1);
    settextstyle(9,0,3);
    delay(1000);
    outtextxy(667,450,(char*)"                                                  ");
}

int Mortage(Player *player,PropHolder holdpos[],int List[],int top){//optimized
    char in;
    bool flag=false;
    ReturnButton();
    setcolor(RED);
    settextjustify(1,1);
    settextstyle(9,0,2);
    setbkcolor(GAME_WIN_COLOR);
    outtextxy(667,450,(char*)"Use Mouse To Mortgage Property");
    while(!flag){
        GetCursorPos(&pnt);
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(pnt.x>=570&&pnt.x<=770&&pnt.y>=150&&pnt.y<=250){
                Remove_RB();
                setcolor(RED);
                outtextxy(667,450,(char*)"                                                           ");
                return 0;
            }
            for(int i=0;i<top;i++){
                if(pnt.x>=holdpos[i].x1&&pnt.x<=holdpos[i].x2&&pnt.y>=holdpos[i].y1&&pnt.y<=holdpos[i].y2&&prop[List[i]].prop_status!='m'){
                    Remove_RB();
                    setcolor(RED);
                    outtextxy(667,450,(char*)"                                                           ");
                    outtextxy(667,450,(char*)prop[List[i]].prop_name);
                    outtextxy(667,500,(char*)"Confirm Mortgage");
                    do{
                        in=getch();
                    }while(!(player->pno==1&&(in==P1YES||in==P1NO))&&!(player->pno==2&&(in==P2YES||in==P2NO)));
                    int res=PlayerSwitch(player->pno,in);
                    if(res==1||res==2){
                        flag=true;
                        prop[List[i]].prop_status='m';
                        modbal(player->pno,prop[List[i]].prop_rate/2);
                        setcolor(5);
                        line(holdpos[i].x1,holdpos[i].y1,holdpos[i].x2,holdpos[i].y2);
                        line(holdpos[i].x2,holdpos[i].y1,holdpos[i].x1,holdpos[i].y2);
                        setbkcolor(GAME_WIN_COLOR);
                        setcolor(RED);
                        settextjustify(1,1);
                        settextstyle(9,0,2);
                        outtextxy(667,450,(char*)"                                                  ");
                        outtextxy(667,500,(char*)"                                  ");
                        return 0;
                    }
                    setbkcolor(GAME_WIN_COLOR);
                    setcolor(RED);
                    settextjustify(1,1);
                    settextstyle(9,0,2);
                    outtextxy(667,450,(char*)"                                                ");
                    outtextxy(667,500,(char*)"                                  ");
                    outtextxy(667,450,(char*)"Mortgage Declined!!");
                    delay(1000);
                    outtextxy(667,450,(char*)"                                              ");
                    return 0;
                }
            }
        }
    }
    setbkcolor(GAME_WIN_COLOR);
    settextjustify(1,1);
    settextstyle(9,0,2);
    outtextxy(667,450,(char*)"                                                 ");
    return 0;
}

int Redeem(Player *player,PropHolder holdpos[],int List[],int top){
    char in;
    bool flag=false;
    ReturnButton();
    setcolor(RED);
    settextjustify(1,1);
    settextstyle(9,0,2);
    setbkcolor(GAME_WIN_COLOR);
    outtextxy(667,450,(char*)"Use Mouse To Redeem Property");
    while(!flag){
        GetCursorPos(&pnt);
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(pnt.x>=570&&pnt.x<=770&&pnt.y>=150&&pnt.y<=250){
                Remove_RB();
                setcolor(RED);
                outtextxy(667,450,(char*)"                                                           ");
                return 0;
            }
            for(int i=0;i<top;i++){
                if(pnt.x>=holdpos[i].x1&&pnt.x<=holdpos[i].x2&&pnt.y>=holdpos[i].y1&&pnt.y<=holdpos[i].y2&&prop[List[i]].prop_status=='m'){
                    Remove_RB();
                    setcolor(RED);
                    outtextxy(667,450,(char*)"                                                           ");
                    outtextxy(667,450,(char*)prop[List[i]].prop_name);
                    outtextxy(667,500,(char*)"Confirm Redeem");
                    do{
                        in=getch();
                    }while(!(player->pno==1&&(in==P1YES||in==P1NO))&&!(player->pno==2&&(in==P2YES||in==P2NO)));
                    int res=PlayerSwitch(player->pno,in);
                    if(res==1||res==2){
                        flag=true;
                        prop[List[i]].prop_status=(char)player->pno;
                        holdpos[i].drawprop(i,player->pno);
                        modbal(player->pno,-prop[List[i]].prop_rate/2);
                        setcolor(BLACK);
                        setbkcolor(GAME_WIN_COLOR);
                        setcolor(RED);
                        settextjustify(1,1);
                        settextstyle(9,0,2);
                        outtextxy(667,450,(char*)"                                                  ");
                        outtextxy(667,500,(char*)"                                  ");
                        return 0;
                    }
                    setbkcolor(GAME_WIN_COLOR);
                    setcolor(RED);
                    settextjustify(1,1);
                    settextstyle(9,0,2);
                    outtextxy(667,450,(char*)"                                                ");
                    outtextxy(667,500,(char*)"                                  ");
                    outtextxy(667,450,(char*)"Redeem Declined!!");
                    delay(1000);
                    outtextxy(667,450,(char*)"                                              ");
                    return 0;
                }
            }
        }
    }
    setbkcolor(GAME_WIN_COLOR);
    settextjustify(1,1);
    settextstyle(9,0,2);
    outtextxy(667,450,(char*)"                                                 ");
    return 0;
}
////Trading Options////////////

int Sell(Player *player,PropHolder holdpos[],int List[],int *top){//optimized
    char in,amt[6]={"     "};
    bool flag=false;
    int amount;
    int res;
    ReturnButton();
    setbkcolor(GAME_WIN_COLOR);
    setcolor(RED);
    settextjustify(1,3);
    settextstyle(9,0,2);
    outtextxy(667,450,(char*)"Use Mouse To Choose Property");
    while(!flag){
        GetCursorPos(&pnt);
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(pnt.x>=570&&pnt.x<=770&&pnt.y>=150&&pnt.y<=250){
                Remove_RB();
                setcolor(RED);
                outtextxy(667,450,(char*)"                                                           ");
                return 0;
            }
            for(int i=0;i<*top;i++){//checking property
                if(pnt.x>holdpos[i].x1&&pnt.x<holdpos[i].x2&&pnt.y>holdpos[i].y1&&pnt.y<holdpos[i].y2&&prop[List[i]].prop_status!='m'){
                    Remove_RB();
                    setcolor(RED);
                    outtextxy(667,450,(char*)"                                                        ");
                    outtextxy(667,450,(char*)prop[List[i]].prop_name);
                    outtextxy(600,500,(char*)"Amount:");
                    for(int j=0;j<6;j++){//getting amount
                        amt[j]=getch();
                        outtextxy(700,500,(char*)"               ");
                        if(amt[j]>='0'&&amt[j]<='9'){
                            outtextxy(700,500,amt);
                        }
                        else if(amt[j]==13){
                            amt[j]='\n';
                            break;
                        }
                        else j--;
                    }
                    outtextxy(700,500,amt);
                    sscanf(amt,"%d",&amount);
                    outtextxy(680,550,(char*)"confirm!!");
                    do{
                        in=getch();
                    }while(!(player->pno==1&&(in==P1YES||in==P1NO))&&!(player->pno==2&&(in==P2YES||in==P2NO)));
                    if(PlayerSwitch(player->pno,in)==5){
                        outtextxy(680,550,(char*)"                             ");
                        outtextxy(600,500,(char*)"                                 ");
                        outtextxy(700,500,(char*)"Deal Cancelled!!");
                        delay(1000);
                        outtextxy(700,500,(char*)"                                      ");
                        outtextxy(667,450,(char*)"                                            ");
                        return 0;
                    }
                    outtextxy(680,550,(char*)"                         ");
                    outtextxy(680,550,(char*)"Except Offer??");
                    do{
                        in=getch();
                    }while(!(player->pno==1&&(in==P2YES||in==P2NO))&&!(player->pno==2&&(in==P1YES||in==P1NO)));
                    outtextxy(680,550,(char*)"                         ");
                    if(player->pno==1)res=PlayerSwitch(2,in);
                    else res=PlayerSwitch(1,in);
                    if(res==1||res==2){
                        flag=true;
                        if(player->pno==1){
                            modbal(2,-amount);
                            modbal(1,amount);
                            list2[p2top]=list1[i];
                            prop[list1[i]].prop_status=(char)2;
                            holdpos2[p2top].drawprop(p2top,2);
                            p2top++;
                            prop[list1[i]].drawFlags(player2.token.color);
                            Shift(&p1top,i,1);
                        }
                        else {
                            modbal(1,-amount);
                            modbal(2,amount);
                            list1[p1top]=list2[i];
                            prop[list2[i]].prop_status=(char)1;
                            holdpos1[p1top].drawprop(p1top,1);
                            p1top++;
                            prop[list2[i]].drawFlags(player1.token.color);
                            Shift(&p2top,i,2);
                        }
                        outtextxy(600,500,(char*)"                                 ");
                        outtextxy(667,450,(char*)"                                            ");
                        return 0;
                    }
                    outtextxy(680,550,(char*)"                                 ");
                    outtextxy(600,500,(char*)"                                 ");
                    outtextxy(700,500,(char*)"Offer Declined!!");
                    delay(1000);
                    outtextxy(700,500,(char*)"                                      ");
                    outtextxy(667,450,(char*)"                                            ");
                    return 0;
                }
            }
        }
    }
    return 0;
}

void Shift(int *top,int i,int pno){//optimized
    int j;
    if(pno==1){
        for(j=i;j<*top-1;j++){
            list1[j]=list1[j+1];
            holdpos1[j].drawprop(j,1);
        }
        holdpos1[j].draw();
    }
    else{
        for(j=i;j<*top-1;j++){
            list2[j]=list2[j+1];
            holdpos2[j].drawprop(j,2);
        }
        holdpos2[j].draw();
    }
    *top-=1;
}

//////Return Button related functions//////////

void ReturnButton(){
    setbkcolor(RED);
    setcolor(BLACK);
    rectangle(570,150,770,250);
    setfillstyle(SOLID_FILL,RED);
    floodfill(571,151,BLACK);
    settextjustify(1,3);
    settextstyle(9,0,3);
    outtextxy(670,190,(char*)"RETURN");
}

void Remove_RB(){
    setbkcolor(GAME_WIN_COLOR);
    setcolor(GAME_WIN_COLOR);
    rectangle(469,149,771,251);
    setfillstyle(SOLID_FILL,GAME_WIN_COLOR);
    floodfill(570,200,GAME_WIN_COLOR);
}

///////////////Option Window Related Functions//////////////////

void Remove_Option(){
    setbkcolor(GAME_WIN_COLOR);
    setcolor(GAME_WIN_COLOR);
    rectangle(539,199,797,477);
    setfillstyle(SOLID_FILL,GAME_WIN_COLOR);
    floodfill(540,200,GAME_WIN_COLOR);
}

void Draw_Option(){
    Remove_Option();
    setcolor(BLACK);
    for(int i=0;i<4;i++){
        rectangle(540+i,200+i,796-i,476-i);
        setfillstyle(SOLID_FILL,BUTTON_COLOR);
        floodfill(541+i,201+i,BLACK);
        line(540,270-i,796,270-i);
        line(540,340-i,796,340-i);
        line(540,410-i,796,410-i);
    }
    settextjustify(1,3);
    settextstyle(9,0,3);
    setbkcolor(BUTTON_COLOR);
    setcolor(WHITE);
    outtextxy(670,225,(char*)"MORTGAGE");
    outtextxy(670,295,(char*)"REDEEM");
    outtextxy(670,365,(char*)"SELL");
    outtextxy(670,435,(char*)"THROW DICE");
}

void OptionHighlight(int OptNo){
    Draw_Option();
    setfillstyle(SOLID_FILL,GREEN);
    setbkcolor(GREEN);
    switch(OptNo){
        case 1: floodfill(545,205,BLACK);
                outtextxy(670,225,(char*)"MORTGAGE");
                break;
        case 2: floodfill(545,271,BLACK);
                outtextxy(670,295,(char*)"REDEEM");
                break;
        case 3: floodfill(545,341,BLACK);
                outtextxy(670,365,(char*)"SELL");
                break;
        case 4: floodfill(545,411,BLACK);
                outtextxy(670,435,(char*)"THROW DICE");
                break;
    }
}

int InputInterpret(int pno,char in){
    if(pno==1){
        if(in==P1throw)return 1;
        if(in==P1choose)return 2;
        if(in==P1YES)return 3;
    }
    else{
        if(in==P2throw)return 1;
        if(in==P2choose)return 2;
        if(in==P2YES)return 3;
    }
    return 0;
}

int Option(int pno){
    Draw_Option();
    int ButtonNo=1;
    char in;
    while(true){
        OptionHighlight(ButtonNo);
        do{
            in=getch();
        }while(!(pno==1&&(in==P1throw||in==P1choose||in==P1YES))&&!(pno==2&&(in==P2throw||in==P2choose||in==P2YES)));
         switch(InputInterpret(pno,in)){
            case 1:ButtonNo--;
                    break;
            case 2:ButtonNo++;
                    break;
            case 3: Remove_Option();
                    return ButtonNo;
         }
         if(ButtonNo==5)ButtonNo=1;
         else if(ButtonNo==0)ButtonNo=4;
    }
}

/////////////Chance////////////

void ChanceMove(int Destination,Player *p1,Player *p2){
    int oldcolor;
    while(p1->token.position!=Destination){
        delay(100);
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
        }
    }
    Move(0,p1,p2);
    prop[p1->token.position].Deal(p1->pno,&p1->cash,p1->token.position);
}

void Chance(Player *p1,Player *p2){
    setbkcolor(GAME_WIN_COLOR);
    settextjustify(1,3);
    settextstyle(1,0,2);
    setcolor(BLUE);
    outtextxy(670,500,(char*)"CHANCE");
    delay(1000);
    outtextxy(670,550,(char*)"                                    ");
    int tmp;
    srand(time(0));
    switch(rand()%10+1){
        case 1:outtextxy(670,500,(char*)"Go To Start");
                ChanceMove(0,p1,p2);
                break;
        case 2:outtextxy(670,500,(char*)"Completed One Round");
                delay(1000);
                modbal(p1->pno,200);
                break;
        case 3:outtextxy(670,500,(char*)"Go To Casino");
                ChanceMove(14,p1,p2);
                break;
        case 4:outtextxy(670,500,(char*)"Lost $200");
                delay(1000);
                modbal(p1->pno,-200);
                break;
        case 5:outtextxy(670,500,(char*)"Go To Jail");
                ChanceMove(21,p1,p2);
                break;
        case 6:outtextxy(670,500,(char*)"Car Repair $100");
                delay(1000);
                modbal(p1->pno,-100);
                break;
        case 7:outtextxy(670,500,(char*)"Insurance Mature $200");
                delay(1000);
                modbal(p1->pno,200);
                break;
        case 8:outtextxy(670,500,(char*)"Your Birthday Get");
               outtextxy(670,550,(char*)"Gift From Your Partner");
                tmp=rand()%200+1;
                delay(1000);
                modbal(p2->pno,-tmp);
                modbal(p1->pno,tmp);
                break;
        case 9:outtextxy(670,500,(char*)"Pay $50 Per Property");
                delay(1000);
                if(p1->pno==1)
                    modbal(p1->pno,-50*p1top);
                else
                    modbal(p1->pno,-50*p2top);
                break;
        case 10:outtextxy(670,500,(char*)"You Got A Lottery");
                tmp=rand()%200+1;
                delay(1000);
                modbal(p1->pno,tmp);
                break;
    }
    setbkcolor(GAME_WIN_COLOR);
    settextjustify(1,3);
    settextstyle(1,0,2);
    outtextxy(670,500,(char*)"                                             ");
    outtextxy(670,550,(char*)"                                             ");
}

///////////////Chest//////////////

void Chest(Player *p1,Player *p2){
    setbkcolor(GAME_WIN_COLOR);
    settextjustify(1,3);
    settextstyle(1,0,2);
    setcolor(BLUE);
    outtextxy(670,500,(char*)"CHEST");
    delay(1000);
    outtextxy(670,550,(char*)"                                    ");
    int tmp;
    srand(time(0));
    switch(rand()%10+1){
        case 1:outtextxy(670,500,(char*)"Go To Start");//ok
                ChanceMove(0,p1,p2);
                break;
        case 2:outtextxy(670,500,(char*)"Bank Error!!$150");//ok
                delay(1000);
                modbal(p1->pno,150);
                break;
        case 3:outtextxy(670,500,(char*)"Doctor's Fee $100");//ok
                delay(1000);
                modbal(p1->pno,-100);
                break;
        case 4:outtextxy(670,500,(char*)"From Stock Sale You Got &50");//ok
                delay(1000);
                modbal(p1->pno,50);
                break;
        case 5:outtextxy(670,500,(char*)"Fund Matures $100");//ok
                delay(1000);
                modbal(p1->pno,100);
                break;
        case 6:outtextxy(670,500,(char*)"School Fee $60");//ok
                delay(1000);
                modbal(p1->pno,-60);
                break;
        case 7:outtextxy(670,500,(char*)"Inherit $100");//ok
                delay(1000);
                modbal(p1->pno,100);
                break;
        case 8:outtextxy(670,500,(char*)"Your Partner's Birthday");//ok
               outtextxy(670,550,(char*)"Gift Your Partner");
                tmp=rand()%200+1;
                delay(1000);
                modbal(p1->pno,-tmp);
                modbal(p2->pno,tmp);
                break;
        case 9:outtextxy(670,500,(char*)"Collect $50 Per Property");//ok
                delay(1000);
                if(p1->pno==1)
                    modbal(p1->pno,50*p1top);
                else
                    modbal(p1->pno,50*p2top);
                break;
        case 10:outtextxy(670,500,(char*)"You Got robbed!!");//ok
                tmp=rand()%200+1;
                delay(1000);
                modbal(p1->pno,-tmp);
                break;
    }
    setbkcolor(GAME_WIN_COLOR);
    settextjustify(1,3);
    settextstyle(1,0,2);
    outtextxy(670,500,(char*)"                                                ");
    outtextxy(670,550,(char*)"                                                ");
}

//////////////Auction///////////////

void Auction_Draw(){
    //////////Clearing screen//////////////
    setcolor(BLUE);
    rectangle(500,150,836,526);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(501,151,BLUE);
    //////////drawing ////

    setcolor(BLACK);
    setbkcolor(YELLOW);
    for(int i=0;i<4;i++){
        rectangle(500+i,150+i,836-i,526-i);
        rectangle(618+i,200+i,718-i,300-i);
        rectangle(618+i,340+i,718-i,380-i);
    }
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(505,155,BLACK);
    settextstyle(1,0,4);
    settextjustify(1,3);
    outtextxy(668,160,(char*)"AUCTION");
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    floodfill(622,204,BLACK);
    setbkcolor(LIGHTBLUE);
    settextjustify(1,1);
    settextstyle(1,0,8);
    outtextxy(668,275,(char*)"?");
    setbkcolor(RED);
}

void AuctionResult(int pno,int bid){
    int cash=(rand()%60+1)*5;
    char tmp[6];

    //////////////Printing of won Status///////////

    setcolor(GAME_WIN_COLOR);
    rectangle(618,340,718,380);
    setbkcolor(GAME_WIN_COLOR);
    setfillstyle(SOLID_FILL,GAME_WIN_COLOR);
    floodfill(619,341,GAME_WIN_COLOR);
    setcolor(BLACK);
    for(int i=0;i<4;i++){
        rectangle(618+i,340+i,718-i,380-i);
    }
    setbkcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(624,345,BLACK);
    settextjustify(1,3);
    settextstyle(1,0,2);
    outtextxy(668,350,(char*)"WON");
    modbal(pno,-bid);

    /////////Getting Profit///////////

    delay(1000);
    setcolor(GAME_WIN_COLOR);
    rectangle(618,200,718,300);
    setbkcolor(GAME_WIN_COLOR);
    setfillstyle(SOLID_FILL,GAME_WIN_COLOR);
    floodfill(619,201,GAME_WIN_COLOR);
    setcolor(BLACK);
    for(int i=0;i<4;i++){
        rectangle(618+i,200+i,718-i,300-i);
    }
    setbkcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    floodfill(624,205,BLACK);
    settextjustify(1,1);
    settextstyle(1,0,4);
    sprintf(tmp,"%d",cash);
    outtextxy(668,260,(char*)tmp);
    delay(1000);
    modbal(pno,cash);

    /////////Auction Remove//////////

    setcolor(GAME_WIN_COLOR);
    rectangle(500,150,836,526);
    setfillstyle(SOLID_FILL,GAME_WIN_COLOR);
    floodfill(505,155,GAME_WIN_COLOR);
}

void Auction(Player *p1,Player *p2){/////Complete It Tomorrow
    Auction_Draw();
    int bid=5;
    char tmp[5]={"    "};
    char in;
    setbkcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(624,345,BLACK);
    settextjustify(1,3);
    settextstyle(1,0,3);
    outtextxy(668,350,(char*)"BID");
    setbkcolor(YELLOW);
    outtextxy(668,400,p1->name);
    sprintf(tmp,"$%d",bid);
    outtextxy(668,450,tmp);
    while(true){
        do{
            in=getch();
        }while(!(p2->pno==1&&(in==P1YES||in==P1NO))&&!(p2->pno==2&&(in==P2YES||in==P2NO)));
        if(PlayerSwitch(p2->pno,in)==1){
            bid+=5;
            sprintf(tmp,"$%d",bid);
        }
        else if(PlayerSwitch(p2->pno,in)==2){
            bid+=5;
            sprintf(tmp,"$%d",bid);
        }
        else{
            AuctionResult(p1->pno,bid);
            break;
        }
        outtextxy(668,400,(char*)"                        ");
        outtextxy(668,450,(char*)"                ");
        outtextxy(668,400,p2->name);
        sprintf(tmp,"$%d",bid);
        outtextxy(668,450,tmp);

        //////////Bid Changes////////////////

        do{
            in=getch();
        }while(!(p1->pno==1&&(in==P1YES||in==P1NO))&&!(p1->pno==2&&(in==P2YES||in==P2NO)));
        if(PlayerSwitch(p1->pno,in)==1){
            bid+=5;
            sprintf(tmp,"$%d",bid);
        }
        else if(PlayerSwitch(p1->pno,in)==2){
            bid+=5;
            sprintf(tmp,"$%d",bid);
        }
        else{
            AuctionResult(p2->pno,bid);
            break;
        }
        outtextxy(668,400,(char*)"                        ");
        outtextxy(668,450,(char*)"                ");
        outtextxy(668,400,p1->name);
        sprintf(tmp,"$%d",bid);
        outtextxy(668,450,tmp);
    }
}

bool LastChance(Player *player,PropHolder holdpos[],int List[],int top,int i){
    int in;
    if(player->cash<prop[List[i]].prop_rate/2)
        return false;
    setbkcolor(GAME_WIN_COLOR);
    setcolor(BLACK);
    settextstyle(1,0,3);
    outtextxy(667,450,(char*)"Last Chance TO Redeem");
    do{
        in=getch();
    }while(!(player->pno==1&&(in==P1YES||in==P1NO))&&!(player->pno==2&&(in==P2YES||in==P2NO)));
    int res=PlayerSwitch(player->pno,in);
    if(res==1||res==2){
        prop[List[i]].prop_status=(char)player->pno;
        holdpos[i].drawprop(i,player->pno);
        modbal(player->pno,-prop[List[i]].prop_rate/2);
        setcolor(BLACK);
        setbkcolor(GAME_WIN_COLOR);
        settextjustify(1,3);
        outtextxy(667,450,(char*)"                                     ");
        return true;
    }
    settextjustify(1,3);
    outtextxy(667,450,(char*)"                                       ");
    return false;
}

bool BankEmpty(){
    for(int i=0;i<28;i++){
        if(prop[i].prop_status=='u'&&prop[i].prop_rate)
            return false;
    }
    return true;
}

bool ColorComplete(int pno,int color){
    for(int i=0;i<28;i++){
        if(prop[i].prop_color==color&&prop[i].prop_status!=(char)pno&&prop[i].prop_rate)
            return false;
    }
    return true;
}

void WhiteProp(int propno,int pno,int pcolor){
    if(prop[propno].prop_status==(char)pno)
    switch(propno){
        case 1:if(prop[4].prop_status==(char)pno){
                    prop[1].multiplier=2;
                    prop[1].drawFlags(pcolor);
                    break;
                }
                else {
                    prop[1].drawFlags(GAME_WIN_COLOR);
                    prop[1].multiplier=1;
                    prop[1].drawFlags(pcolor);
                    break;
                }
        case 4:if(prop[10].prop_status==(char)pno){
                    prop[4].multiplier=2;
                    prop[4].drawFlags(pcolor);
                    break;
                }
                else {
                    prop[4].drawFlags(GAME_WIN_COLOR);
                    prop[4].multiplier=1;
                    prop[4].drawFlags(pcolor);
                    break;
                }
        case 10:if(prop[18].prop_status==(char)pno){
                    prop[10].multiplier=2;
                    prop[10].drawFlags(pcolor);
                    break;
                }
                else {
                    prop[10].drawFlags(GAME_WIN_COLOR);
                    prop[10].multiplier=1;
                    prop[10].drawFlags(pcolor);
                    break;
                }
        case 18:if(prop[23].prop_status==(char)pno){
                    prop[18].multiplier=2;
                    prop[18].drawFlags(pcolor);
                    break;
                }
                else {
                    prop[18].drawFlags(GAME_WIN_COLOR);
                    prop[18].multiplier=1;
                    prop[18].drawFlags(pcolor);
                    break;
                }
        case 23:if(prop[1].prop_status==(char)pno){
                    prop[23].multiplier=2;
                    prop[23].drawFlags(pcolor);
                    break;
                }
                else {
                    prop[23].drawFlags(GAME_WIN_COLOR);
                    prop[23].multiplier=1;
                    prop[23].drawFlags(pcolor);
                    break;
                }
    }
}


