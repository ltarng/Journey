#include"console.h"
int main()
{
    srand(time(0));/*Notice the position to put this*/
    /*Tell Story*/
    prologue();
    gotoXY(0,5);
    introduction_battle();
    gotoXY(0,5);
    guide();
    /*create player and monster data*/
    all_player allp;
    all_monster allm;
    create_player(&allp);
    read_monster(&allm);
    /*Game Start*/
    int end = 0, input = 0;
    int role_x = 17, role_y = 4, section = 1;/*setting initial position*/
    int *rx = &role_x, *ry = &role_y;
    role_move(0, 0, rx, ry, &section, &allp);/*Map ,x means up and down ,y means left and right*/
    do
    {
        if(kbhit())/*move and control*/
        {
            input = getch();/*keyboard*/
            switch(input)
            {
            case 0x4B:/*left*/
                end = role_move(0, -1, rx, ry, &section, &allp);
                if(rand()%40 < 1)/*the probability to encounter monster*/
                {
                    monster_encounter(&section, allm, &allp);/*encounter monster*/
                    end = role_move(0, -1, rx, ry, &section, &allp);/*after battle,walk*/
                }
                break;
            case 0x4D:/*right*/
                end=role_move(0, 1, rx, ry, &section, &allp);
                if(rand()%40 < 1)
                {
                    monster_encounter(&section, allm, &allp);
                    end = role_move(0, 1, rx, ry, &section, &allp);
                }
                break;
            case 0x48:/*up*/
                end = role_move(-1, 0, rx, ry, &section, &allp);
                if(rand()%40<1)
                {
                    monster_encounter(&section, allm, &allp);
                    end = role_move(-1, 0, rx, ry, &section, &allp);
                }
                break;
            case 0x50:/*down*/
                end=role_move(1, 0, rx, ry, &section, &allp);
                if(rand()%40<1)
                {
                    monster_encounter(&section, allm, &allp);
                    end = role_move(1, 0, rx, ry, &section, &allp);
                }
                break;
            case 0x0D:/*enter*/
            {
                char *words[6]= {"\t\t   遊戲手冊"," ","N代表NPC","H代表梯子","DL代表神龍王","FP代表維修點"};
                system("cls");
                battle_star();
                int i=0;
                for(i=0; i<6; i++)
                {
                    gotoXY(23, 4+i);
                    puts(words[i]);
                }
                gotoXY(23,5+i);
                system("pause");
                system("cls");
                end=role_move(0, 0, rx, ry, &section, &allp);
            }
            break;
            case 27:/*Esc*/
                end = 1;
                break;
            }
        }
        //Sleep(70);
    }
    while(end!=1 && allp.state!=-1);
    colorNum color;
    if(end==1)
    {
        setColor(Cyan);
        printf("\n\n\n\n\t\t\tThanks for your play!!\n\n\n");
        setColor(White);
        Sleep(3000);
    }
    else
    {
        setColor(Red);
        printf("\n\n\n\n\t\tOops, game over. You can try again next time %c\n\n\n",1);
        setColor(White);
    }
    return 0;
}
