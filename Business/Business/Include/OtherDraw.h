void drawInput(){
    int i=0,j=0,x=40,choice_color,dt_num;
    char dt_str[2];
    graphdefaults();
    setbkcolor(FST_SCR_COLOR);
    cleardevice();
    settextstyle(7,0,4);
    outtextxy(370,50,(char*)"WELCOME TO BUSINESS GAME");
    settextstyle(4,0,2);
    outtextxy(500,130,(char*)"Please Enter Player Details");
    line(683,170,683,690);
    line(0,170,1360,170);
    settextstyle(3,0,3);
    setbkcolor(CYAN);
    outtextxy(310,180,(char*)"Player 1");
    outtextxy(975,180,(char*)"Player 2");
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

