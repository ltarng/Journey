#include"console.h"
void blank(const int blank, const int pause, const int change_line, const int blank2){
    /* ( blank space to window ,  , space between line to line , blank space to window )*/
    for(int i=0; i<blank; i+=1) printf(" ");/*left to right make blank*/
    for(int i=0; i<pause; i+=1) system("pause");
    for(int i=0; i<change_line; i+=1) printf("\n");
    for(int i=0; i<blank2; i+=1) printf(" ");
}

void npc_dialogue(char *words[], const int dialogue_size){
    int i=0;
    event_star();
    for(i=0; i<dialogue_size; i++)
    {
        gotoXY(8,17+i);
        puts(words[i]);
        Sleep(700);
    }
    gotoXY(51,17);/*(L.R,U.D)*/
    system("pause");
}

void battle_star(){
    setColor(Cyan);
    blank(0,0,2,20);
    for(int i=0; i<45; i++) printf("*");
    blank(0,0,1,20);
    for(int i=0; i<13; i++)
    {
        printf("*");
        blank(43,0,0,0);
        printf("*");
        blank(0,0,1,20);
    }
    for(int i=0; i<45; i++) printf("*");
    setColor(White);
}

void event_star(){
    setColor(Cyan);
    gotoXY(6,16);
    for(int i=0; i<67; i++) printf("*");
    blank(0,0,1,6);
    for(int i=0; i<6; i++)
    {
        printf("*");
        blank(65,0,0,0);
        printf("*");
        blank(0,0,1,6);
    }
    for(int i=0; i<67; i++) printf("*");
    setColor(White);
}

void map_icon(int (*point)[22],int *rx,int *ry,int *section){  //在地圖移動時 print
    setColor(White);
    gotoXY(0,6);
    for(int i=*rx-4; i<*rx+4; i+=1)
    {
        blank(22,0,0,10);
        for(int j=*ry-4; j<*ry+4; j+=1)
        {
            switch(point[i][j])/*icon on map*/
            {
            case 0:
                printf("  ");/*nothing is here*/
                break;
            case 1:
                setColor(DarkYellow);
                printf("%c ",35);/*as sand ground*/
                setColor(White);
                break;
            case 2:
                setColor(DarkGreen);
                printf("%c ",5);/*as a tree*/
                setColor(White);
                break;
            case 3:
                printf("%c ",30);/*as building █*/
                break;
            case 10:
                setColor(Cyan);
                printf("%c ",15);/*as magic icon*/
                setColor(White);
                break;
            case 11:
                setColor(Gray);
                printf("%c ",21);/*as broken*/
                setColor(White);
                break;
            case 7:
                printf(" H");/*as floor*/
                break;
            case 8:
                setColor(Yellow);
                printf("%c/",1);/*icon : Player with a sword(or stick?)*/
                setColor(White);
                break;
            case 50:
                setColor(Magenta);
                printf("%c ",3);/*Helper*/
                setColor(White);
                break;
            case 100:
                setColor(Yellow);
                printf("N ");/*NPC*/
                setColor(White);
                break;
            case 500:
                setColor(Cyan);
                printf("T ");/*tips*/
                setColor(White);
                break;
            case 1000:
                setColor(Red);
                printf("FP");/*Fix Point*/
                setColor(White);
                break;
            case 10000:
                setColor(Cyan);
                printf("DL");/*Drgon Lord*/
                setColor(White);
                break;
            default:
                printf("XX");/*error*/
                break;
            }
        }
        printf("\n");
    }
}

void clear(const int i_size,const int j,const int j_size,const int x){  /*(long,from y start,heigh,from x start)*/
    for(int y=j; y<j_size; y+=1)
    {
        gotoXY(x,y);
        for(int i=0; i<i_size; i+=1) printf(" ");
    }
}

void clear_dialogue(){
    clear(67,16,24,6);
}

void clear_event(const int j){
    clear(67,j,19,15);
}

void clear_battle_star(const int j){
    clear(37,j,16,22);
}
