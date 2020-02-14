
void Decide_Winner(){
    char tmp[7];
    cleardevice();
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(0,0,BLUE);
    setcolor(BLUE);
    for(int i=0;i<4;i++){
        rectangle(90+i,100+i,665+i,586+i);//Outer box
        rectangle(685+i,100+i,1265+i,586+i);//Outer Box

        rectangle(115+i,125+i,640+i,561+i);//inner box
        rectangle(710+i,125+i,1240+i,561+i);//inner box

        rectangle(150+i,280+i,350+i,380+i);//left eye
        rectangle(745+i,280+i,945+i,380+i);//left eye

        rectangle(420+i,280+i,620+i,380+i);//Right eye
        rectangle(1015+i,280+i,1215+i,380+i);//Right eye

        rectangle(285+i,430+i,485+i,530+i);//mouth
        rectangle(880+i,430+i,1080+i,530+i);//mouth

    }
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    floodfill(95,105,BLUE);
    floodfill(690,105,BLUE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(120,130,BLUE);
    floodfill(715,130,BLUE);
    setbkcolor(WHITE);
    settextjustify(1,3);
    settextstyle(1,0,5);
    setcolor(BLUE);
    outtextxy(377,150,player1.name);
    outtextxy(975,150,player2.name);
    settextstyle(1,0,3);

    outtextxy(250,250,(char*)"Cash Value");
    outtextxy(850,250,(char*)"Cash value");
    outtextxy(527,250,(char*)"Prop Value");
    outtextxy(1125,250,(char*)"Prop Value");
    outtextxy(388,400,(char*)"Total Value");
    outtextxy(985,400,(char*)"Total value");

    setbkcolor(YELLOW);
    sprintf(tmp,"$%d",player1.cash);
    outtextxy(250,320,tmp);
    sprintf(tmp,"$%d",player2.cash);
    outtextxy(850,320,tmp);
    int Total1=0,Total2=0;
    for(int i=0;i<p1top;i++){
        if(prop[list1[i]].prop_status==(char)player1.pno)
            if(prop[list1[i]].multiplier==2&&prop[list1[i]].prop_color!=WHITE)
                Total1+=prop[list1[i]].prop_rate*1.5;
            else
                Total1+=prop[list1[i]].prop_rate;
    }
    for(int i=0;i<p2top;i++){
        if(prop[list2[i]].prop_status==(char)player2.pno)
            Total2+=prop[list2[i]].prop_rate;
    }
    sprintf(tmp,"$%d",Total1);
    outtextxy(527,320,tmp);
    sprintf(tmp,"$%d",Total2);
    outtextxy(1125,320,tmp);
    sprintf(tmp,"$%d",Total1+player1.cash);
    outtextxy(388,470,tmp);
    sprintf(tmp,"$%d",Total2+player2.cash);
    outtextxy(985,470,tmp);
    int a=2;
    for(int i=0;i<100;i++){
        if(Total1+player1.cash>=Total2+player2.cash){
            setfillstyle(SOLID_FILL,a++);
            floodfill(95,105,BLUE);
        }
        else if(Total1+player1.cash<Total2+player2.cash){
            setfillstyle(SOLID_FILL,a++);
            floodfill(690,105,BLUE);
        }
        else {
            settextstyle(1,0,7);
            outtextxy(667,20,(char*)"DRAW");
        }
        if(a==16)a=2;
        delay(150);
    }
    getch();
    exit(0);
}





