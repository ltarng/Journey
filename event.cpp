#include"console.h"
void NPC_tips(const int *section, const int npc_t_num)
{
    if(*section==1)
    {
        switch(npc_t_num)
        {
        case 1:/*introduce monster*/
        {
            char words[15][80]= {"(1)hoed:","They almost keep murmuring.","Actually, they usually stay at the same place.",
                                 "(2)koloss:","Koloss have blue skin.","They are large and dangerous!",
                                 "(3)orc :","Not so smart, but they are strong.","Face is generally a mixture of the ape-like and pig-like.",
                                 "(4)black dragon Amurtaat :","Also called as A SURVEILLANT OF SUNSET in the world.","As all dragons, with high intelligent but they are dangerous."
                                };
            event_star();
            for(int j=0; j<2; j+=1)
            {
                for(int i=0; i<6; i+=1)
                {
                    gotoXY(8,17+i);
                    puts(words[i+j*6]);
                    Sleep(700);
                }
                Sleep(3000);
            }
            gotoXY(51,17);/*(L.R,U.D)*/
            system("pause");

            break;
        }
        case 2:/*Another helper*/
        {
            char *words[6]= {"Hello!","I know you are the people want to help Elantris!",
                             "You can ask Dragon Lord how to save it.","I don't know where is Dragon Lord.",
                             "But there is a golden dragon live in Eternal Forest.","Good luck!!"
                            };
            npc_dialogue(words,6);
        }
        break;
        }
    }
    else if(*section==2)
    {
        switch(npc_t_num)
        {
        case 1:/*Kradmesser*/
        {
            char *words[7]= {"Steel Inquisitor......?","......Hey!","Do you know here live a golden dragon?","Yes, its name is Dragon Lord!",
                             "Oh, you are welcomed.","My name is Kradmesser! Nice to meet you!!"
                            };
            npc_dialogue(words,7);
        }
        break;
        case 2:/*Dragon Lord*/
        {
            char *words[6]= {"I haven't see human for a long time.","Most of them will get lost in Eternal Forest.","You want to save Elantris?",
                             "Haha! So interesting, right?","Just use your power on a special place!","That's a hint!! Bye-bye!"
                            };
            npc_dialogue(words,6);
        }
        }
    }
    else
    {
        char *words[5]= {"This magic circle had broken......","............","What? You want to save Elantris?","There is a mystery point, you know how to do!","Go, go, go, go!"};
        npc_dialogue(words,5);
    }
}
int map_event(const int *rx,const int *ry,int *section,all_player *allp)//have bug
{
    int npc_num=0;
    if(*section==1)//Midland Way
    {
        setColor(BlueOnW);
        gotoXY(18,15);
        printf(" -Elantris to Eternal Forest-Midland Way- ");/*Elantris to Eternal Forest-Midland Way*/
        setColor(White);
        if(*rx==4 && *ry==17)
        {
            *section=2;
            system("cls");
            setColor(BlueOnW);
            gotoXY(30,15);
            printf(" -Eternal Forest- ");/*Eternal Forest*/
            setColor(White);
        }
        else if(*rx==17 && *ry==9)/*introduce monster*/
        {
            npc_num=1;
            NPC_tips(section,npc_num);
            clear_dialogue();
        }
        else if(*rx==6 && *ry==10)/*where is golden Dragon?*/
        {
            npc_num=2;
            NPC_tips(section,npc_num);
            clear_dialogue();
        }
    }
    else if(*section==2)//Eternal Forest
    {
        setColor(BlueOnW);
        gotoXY(30,15);
        printf(" -Eternal Forest- ");/*Eternal Forest*/
        setColor(White);
        if(*rx==4 && *ry==17)/*to Elantris to Eternal Forest - Midland Way*/
        {
            *section=1;
            system("cls");
            setColor(BlueOnW);
            gotoXY(18,15);
            printf(" -Elantris to Eternal Forest-Midland Way- ");/*Elantris to Eternal Forest-Midland Way*/
            setColor(White);
        }
        else if(*rx==17 && *ry==15)/*to Broken Magic Circle*/
        {
            *section=3;
            system("cls");
            setColor(BlueOnW);
            gotoXY(24,15);
            printf(" -Broken Mystery Magic Circle- ");/*Broken Mystery Magic Circle*/
            setColor(White);
        }
        else if(*rx==8 && *ry==11)/*dragon is near*/
        {
            npc_num=1;
            NPC_tips(section,npc_num);
            clear_dialogue();
        }
        else if(*rx==7 && *ry==6)/*Dragon Lord*/
        {
            npc_num=2;
            NPC_tips(section,npc_num);
            clear_dialogue();
            allp->state=1;//get final tips
        }
    }
    else//Magic Circle
    {
        setColor(BlueOnW);
        gotoXY(24,15);
        printf(" -Broken Mystery Magic Circle- ");/*Broken Mystery Magic Circle*/
        setColor(White);
        if(*rx==17 && *ry==15)/*back to Eternal Forest*/
        {
            *section=2;
            system("cls");
            setColor(BlueOnW);
            gotoXY(30,15);
            printf(" -Eternal Forest- ");/*Eternal Forest*/
            setColor(White);
        }
        else if(*rx==6 && *ry==7)/*Fix Point*/
        {
            if(allp->state==1)
            {
                char *words[5]= {"You wrote some magic word on the ground......","............","You feel a power start flowing in the air.","The circle is glowing!!","You feel the power of magic is recovered!!"};
                int i=0;
                event_star();
                for(i=0; i<5; i++)
                {
                    gotoXY(8,17+i);
                    puts(words[i]);
                    Sleep(1000);
                }
                gotoXY(51,17);
                Sleep(3000);
                system("cls");
                gotoXY(17,7);
                printf("You sucessfully fix this magic circle!");/*You sucessfully save Elantris*/
                gotoXY(16,9);
                printf("You save Elantris! Thanks for your help!");/*Thanks for your help*/
                setColor(Yellow);
                gotoXY(22,11);
                printf("********Game Clear********");/*Game Clear*/
                setColor(Green);
                gotoXY(22,15);
                printf("   Bye!Have a nice day!");
                Sleep(4000);
                setColor(White);
                return 1;
            }
            else
            {
                char *words[6]= {"You put your hand on the ground.......",".........","......................","You wait for several seconds.","But nothing happened.","Maybe you should find someone first?"};
                int i=0;
                event_star();
                for(i=0; i<6; i++)
                {
                    gotoXY(8,17+i);
                    puts(words[i]);
                    Sleep(1000);
                }
                gotoXY(51,17);/*(L.R,U.D)*/
                system("pause");
                clear_dialogue();
            }
        }
        else if(*rx==14 && *ry==14)/*Helper*/
        {
            npc_num=1;
            NPC_tips(section,npc_num);
            clear_dialogue();
        }
    }
    return 0;
}
int role_move(int x,int y,int *rx,int *ry,int *section,all_player *allp)/*player move and S&L map*//*Save Load*/
{
    /*read map*/
    int map[map_size][map_size]= {0};
    char map_name[30]="";
    map_name[0]='0'+*section;
    strcat(map_name,".map");
    read_map(map_size,map_name,map);
    /*print map*/
    if((map[*rx+x][*ry+y]!=1) && (map[*rx+x][*ry+y]!=2) && (map[*rx+x][*ry+y]!=3))/*prevent player go into wall*/
    {
        *rx+=(x),*ry+=(y);/*renew player's position*/
        map[*rx][*ry]=8;/*print player icon*/
    }
    else
    {
        map[*rx][*ry]=8;/*player icon*/
    }
    map_icon(map,rx,ry,section);/*print icon*/
    int end=0;
    return end=map_event(rx,ry,section,allp);
}

