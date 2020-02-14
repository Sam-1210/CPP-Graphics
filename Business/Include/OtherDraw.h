void PrimarySCR(){
    PlaySound("SFX\\MM.BGA",NULL,SND_LOOP | SND_ASYNC);
    int i,j,k,lod_runtime,rand_color;
    graphdefaults();
    setbkcolor(WHITE);
    cleardevice();
    settextjustify(1,1);
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    for(i=0;i<10;i++){
        arc(623,200,45,270,40-i);
        arc(622,270,180,90,40-i);
        delay(50);
    }
    for(i=0;i<10;i++){
        arc(743,200,45,270,40-i);
        arc(742,270,180,90,40-i);
        delay(50);
    }
    setcolor(BLACK);
    settextstyle(8,0,5);
    for(i=500;i<=683;i+=25){
        outtextxy(i,375,(char*)"                         ");
        outtextxy(i,370,(char*)"C++ GAMES");
        delay(15);
    }
    srand(time(0));
    lod_runtime=rand()%270+150;
    rand_color=rand()%11+1;
    settextstyle(8,0,3);
    setcolor(LIGHTRED);
    outtextxy(1225,670,(char*)"Loading");
    for(i=0,k=0;i<=lod_runtime;i++){
        if(i%30==0){
            for(j=i-30;j<=i;j++){
                setcolor(WHITE);
                setfillstyle(SOLID_FILL,WHITE);
                pieslice(1230,600,j,j+5,40);
                floodfill(1230,600,WHITE);
                delay(0);
            }
            i+=5;
        }
        setcolor(rand_color);
        setfillstyle(SOLID_FILL,rand_color);
        pieslice(1230,600,i,i+5,40);
        floodfill(1230,600,WHITE);
        outtextxy(1280+k,670,(char*)".");
        k++;
        if(k==18)k=0;
        delay(0);
    }
    MainMenu();
}

void MainMenu(){
    DrawMM();
    InputMM();
}

void Diomond(int Cx,int Cy,int Radius){
    line(Cx,Cy-Radius,Cx+Radius,Cy);
    line(Cx+Radius,Cy,Cx,Cy+Radius);
    line(Cx,Cy+Radius,Cx-Radius,Cy);
    line(Cx-Radius,Cy,Cx,Cy-Radius);
}

void DrawMM(){
    graphdefaults();
    setbkcolor(FST_SCR_COLOR);
    cleardevice();
    settextjustify(1,0);
    settextstyle(1,0,4);
    outtextxy(667,50,(char*)"WELCOME TO BUSINESS GAME");
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    Diomond(100,250,100);
    floodfill(100,250,RED);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    circle(100,250,25);
    floodfill(100,250,WHITE);
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    Diomond(150,350,100);
    floodfill(150,350,GREEN);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    circle(108,351,25);
    circle(150,310,25);
    circle(170,380,25);
    floodfill(108,351,WHITE);
    floodfill(150,310,WHITE);
    floodfill(170,380,WHITE);
}

void InputMM(){
    int in,cur_op=0;
    setbkcolor(FST_SCR_COLOR);
    setcolor(WHITE);
    settextjustify(2,1);
    settextstyle(8,0,5);
    outtextxy(1355,250,(char*)"PLAY!!!");
    outtextxy(1355,300,(char*)"Records");
    outtextxy(1355,350,(char*)"Help & Support");
    outtextxy(1355,400,(char*)"Exit");
    setbkcolor(LIGHTBLUE);
    outtextxy(1355,250,(char*)"PLAY!!!");
    setbkcolor(FST_SCR_COLOR);
    while(true){
        in=getch();
        outtextxy(1355,250,(char*)"PLAY!!!");
        outtextxy(1355,300,(char*)"Records");
        outtextxy(1355,350,(char*)"Help & Support");
        outtextxy(1355,400,(char*)"Exit");
        if(in==GetAsyncKeyState(VK_UP))
            cur_op++;
        else if(in==GetAsyncKeyState(VK_DOWN))
        cur_op--;
        else if(in==13){
            doMM(cur_op);
            break;
        }
        switch(cur_op){
            case 0: setbkcolor(LIGHTBLUE);
                    outtextxy(1355,250,(char*)"PLAY!!!");
                    setbkcolor(FST_SCR_COLOR);
                    break;
            case 1:setbkcolor(LIGHTBLUE);
                    outtextxy(1355,300,(char*)"Records");
                    setbkcolor(FST_SCR_COLOR);
                    break;
            case 2:setbkcolor(LIGHTBLUE);
                    outtextxy(1355,350,(char*)"Help & Support");
                    setbkcolor(FST_SCR_COLOR);
                    break;
            case 3: setbkcolor(LIGHTBLUE);
                    outtextxy(1355,400,(char*)"Exit");
                    setbkcolor(FST_SCR_COLOR);
                    break;
        }
        if(cur_op<0)cur_op=3;
        else if(cur_op==4)cur_op=0;
    }
}

void doMM(int op){
    switch(op){
    case 1: DisplayRecords();
    break;
    case 2: //Help();
    break;
    case 3:
        exit(0);
    }
}

void DisplayRecords(){
    setcolor(BLACK);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    bar3d(400,100,900,650,5,1);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(901,101,BLACK);
    floodfill(405,99,BLACK);
    setbkcolor(LIGHTMAGENTA);
    settextstyle(4,0,4);
    settextjustify(0,2);
    outtextxy(430,110,(char*)"WINNER");
    outtextxy(690,110,(char*)"LOSER");
    settextstyle(8,0,4);
    file2=fopen("Records.BGR","rb");
    if(file2==NULL){
        settextjustify(1,1);
        outtextxy(650,375,(char*)"No Records!!!");
        return;
    }
    for(int i=0;i<12&&!(feof(file2));i++){
        strcpy(tmp.win,"            ");
        strcpy(tmp.los,"            ");
        strcpy(tmp.win_amt,"     ");
        strcpy(tmp.los_amt,"     ");
        fread(&tmp,sizeof(tmp),1,file2);
        settextjustify(0,2);
        outtextxy(420,160+i*40,tmp.win);
        outtextxy(670,160+i*40,tmp.los);
        settextjustify(2,2);
        outtextxy(640,160+i*40,tmp.win_amt);
        outtextxy(890,160+i*40,tmp.los_amt);
    }
}

void drawInput(){
    int i=0,j=0,x=40,choice_color,dt_num;
    char dt_str[2];
    graphdefaults();
    setbkcolor(FST_SCR_COLOR);
    cleardevice();
    settextjustify(1,0);
    settextstyle(1,0,4);
    outtextxy(667,50,(char*)"WELCOME TO BUSINESS GAME");
    settextstyle(4,0,2);
    outtextxy(667,130,(char*)"Please Enter Player Details");
    line(683,170,683,690);
    line(0,170,1360,170);
    settextstyle(3,0,3);
    setbkcolor(CYAN);
    outtextxy(310,210,(char*)"Player 1");
    outtextxy(975,210,(char*)"Player 2");
    setbkcolor(FST_SCR_COLOR);
    settextstyle(3,0,2);
    for(;x<781;x+=680){
        settextjustify(0,3);
        outtextxy(x,240,(char*)"Name: ");
        outtextxy(x,280,(char*)"Dice Color: ");
        outtextxy(x,390,(char*)"Token Color: ");
        for(i=0,j=x,choice_color=1,dt_num=1;i<450;i+=50,choice_color++,dt_num++){
            if(choice_color==3){++choice_color;}
            setcolor(BLACK);
            rectangle(j+i,320,j+i+50,370);
            setfillstyle(SOLID_FILL,choice_color);
            floodfill(j+i+1,321,BLACK);
            setbkcolor(choice_color);
            setcolor(WHITE);
            sprintf(dt_str,"%d",dt_num);
            settextjustify(1,3);
            outtextxy(j+i+25,335,dt_str);
            j+=20;
        }
        for(i=0,j=x,choice_color=1,dt_num=1;i<150;i+=50,choice_color++,dt_num++){
            if(choice_color==3)++choice_color;
            setcolor(BLACK);
            circle(j+i+220,450,25);
            setfillstyle(SOLID_FILL,choice_color);
            floodfill(j+i+220,450,BLACK);
            setbkcolor(choice_color);
            setcolor(WHITE);
            sprintf(dt_str,"%d",dt_num);
            settextjustify(1,3);
            outtextxy(j+i+220,437,dt_str);
            j+=20;
        }
        setbkcolor(FST_SCR_COLOR);
    }
    userInput(player1.name,&player1.dice.color,&player1.token.color,&player1.token.texture,40,0);
    userInput(player2.name,&player2.dice.color,&player2.token.color,&player2.token.texture,720,1);
    getch();
}

void userInput(char tmp[PLAYER_NAME],int *dc,int *tc,int *tt,int x,bool flag){
    int i=0;
    char dice_color[2],token_color[2];
    settextjustify(0,3);
    while(i<PLAYER_NAME-2){
        tmp[i]=getch();
        outtextxy(x+200,650,(char*)"                                              ");
        if((tmp[i]>64&&tmp[i]<91)||(tmp[i]>96&&tmp[i]<123)){
            outtextxy(x+150,240,tmp);
            i++;
        }
        else if(tmp[i]==8){
            outtextxy(x+150,240,(char*)"                   ");
            tmp[i]=' ';
            tmp[i-1]=' ';
            if(i)i--;
            outtextxy(x+150,240,tmp);
        }
        else if(tmp[0]==13){
            outtextxy(x+200,650,(char*)"ERROR: name too short");
            continue;
        }
        else if(tmp[i]==13&&i!=0){
                tmp[i+1]='\0';
                break;
        }
        else{
            outtextxy(x+200,650,(char*)"Illegal Character!!!");
            continue;
        }
    }
l1:     dice_color[0]=getch();
        dice_color[1]='\0';
        sscanf(dice_color,"%d",dc);
        outtextxy(x+200,650,(char*)"                                              ");
        if(*dc>0&&*dc<10){
            outtextxy(x+150,280,dice_color);
            if(*dc>=3){
                ++*dc;
            }
        }
        else if(dice_color[0]==13){
            outtextxy(x+200,650,(char*)"Field Can't Be Empty!!!");
            goto l1;
        }
        else{
            outtextxy(x+200,650,(char*)"Invalid Choice!!!");
            goto l1;
        }
l2:     token_color[0]=getch();
        token_color[1]='\0';
        sscanf(token_color,"%d",tc);
        outtextxy(x+200,650,(char*)"                                                                    ");
        if(*tc>0&&*tc<4){
            if(*tc==3){
                *tc=4;
            }
            if(flag==1){
                if(*tc==player1.token.color){
                    outtextxy(x+200,650,(char*)"Both Players Can't Have Same Colors!!!");
                    goto l2;
            }   }
            outtextxy(x+150,390,token_color);
        }
        else if(token_color[0]==13){
            outtextxy(x+200,650,(char*)"Field Can't Be Empty!!!");
            goto l2;
        }
        else{
            outtextxy(x+200,650,(char*)"Invalid Choice!!!");
            goto l2;
        }
}

void versusWindow(){
    char str1[10],str2[10];
    sprintf(str1,"US$ %d",player1.cash);
    sprintf(str2,"US$ %d",player2.cash);
    graphdefaults();
    setbkcolor(YELLOW);
    setcolor(BLACK);
    cleardevice();
    settextstyle(7,0,4);
    outtextxy(370,50,(char*)"WELCOME TO BUSINESS GAME");
    outtextxy(610,300,(char*)"V/S");
    settextstyle(8,0,3);
    setcolor(BLACK);
    rectangle(240,234,310,305);
    setfillstyle(SOLID_FILL,player1.dice.color);
    floodfill(241,236,BLACK);
    setcolor(player1.token.color);
    circle(355,270,35);
    setfillstyle(player1.token.texture,player1.token.color);
    floodfill(355,270,player1.token.color);
    setcolor(WHITE);
    circle(275,270,10);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(275,270,15);
    setcolor(BLACK);
    rectangle(940,235,1010,305);
    setfillstyle(SOLID_FILL,player2.dice.color);
    floodfill(941,236,BLACK);
    setcolor(WHITE);
    circle(985,260,10);
    circle(965,280,10);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(985,260,WHITE);
    floodfill(965,280,WHITE);
    setcolor(player2.token.color);
    circle(1055,270,35);
    setfillstyle(player2.token.texture,player2.token.color);
    floodfill(1055,270,player2.token.color);
    setcolor(BLACK);
    outtextxy(250,325,player1.name);
    outtextxy(950,325,player2.name);
    outtextxy(250,360,str1);
    outtextxy(950,360,str2);
    char str[3][8]={"READY","SET","DEAL:-)"};
    for(int i=0;i<3;i++){
        outtextxy(625,500,(char*)"             ");
        outtextxy(625,500,str[i]);
        delay(800);
    }
    settextstyle(2,0,7);
    outtextxy(525,600,(char*)"PRESS ANY KEY TO START...");
    delay(800);
    getch();
}

