#include"console.h"
int UltimateCode(int guess,int this_turn_low,int this_turn_high,const int low,const int high)//have bug
{
    constexpr int max_turn=2;/*max turn can use*/
    this_turn_low=1,this_turn_high=25;
    int ans=0;
    int decide_point;
    ans=rand()%(high-low-1)+low+1;/*the min and max number can't guess*/
    for(int i=1; i<max_turn; i+=1)
    {
        if (ans == guess)
        {
            printf("Congratulations!\n");
            break;
        }
        else if (guess>ans)
        {
            printf("Answer is between %d-%d.\n",this_turn_low,guess);
            this_turn_high=guess;
        }
        else if (guess<ans)
        {
            printf("Answer is between %d-%d.\n",guess,this_turn_high);
            this_turn_low=guess;
        }
        printf("Please guess a number between %d-%d:",this_turn_low,this_turn_high);
        scanf("%d",&guess);
    }
    decide_point=ans-guess;
    if(decide_point<0)
    {
        decide_point=-decide_point;//*get positive number
    }
    if(ans==guess) printf("\nCongratulations!\n");
    else
    {
        printf("\nSorry ,but you got a wrong answer...");
        printf("\nThe answer is %d ,and there is %d number difference.\n",ans,decide_point);
    }
    Sleep(2000);
    system("pause");
    return decide_point;
}
int decide_player_hp_atk(int decide_point)
{
    if(decide_point<=1) return 3;/*LV4*/
    else if(decide_point<=3) return 2;/*LV3*/
    else if(decide_point<=5) return 1;/*LV2*/
    else return 0;/*LV1*/
}
int battle(const int monster_num,all_monster allm,all_player *allp)
{
//*******************************************************player point decide
    constexpr int low=1,high=25;
    int guess=0;
    setColor(Red);
    printf("%c Notice:No provide re-input when input a number over the range.\n",15);/*%c=5 is a icon*/
    setColor(White);
    printf("Please guess a number in %d-%d:",low,high);
    scanf("%d",&guess);
    int decide_player=decide_player_hp_atk(UltimateCode(guess,low,high,low,high));/*play UltimateCode*/
    system("cls");/*clear guess record*/
//*******************************************************player point decide
    int player_hp=allp->player[decide_player].hp;
    int player_atk=allp->player[decide_player].atk;
    int player_life=player_hp;
    int player_c_atk=player_atk*2;
    int player_atk_decide,hit_decide,option=0,escape_secide;
//*************************************player's capability end
    char mon_name[25];
    strcpy(mon_name,allm.monsters[monster_num].name);
    int mon_life=allm.monsters[monster_num].hp;
    int mon_n_hit=allm.monsters[monster_num].atk;
    int mon_c_hit=allm.monsters[monster_num].atk*2;
//************************monster capability end
    /*Battle Start*/
    do
    {
        battle_star();
        /*Life Print*/
        gotoXY(23,4);
        printf("%s  HP:%d/%d",mon_name,mon_life,allm.monsters[monster_num].hp);
        gotoXY(23,5);
        printf("Your life %d/%d\n\n",player_life,player_hp);
        /*Player Attack*/
        gotoXY(23,7);
        printf("Action choice");
        gotoXY(26,8);
        printf("(1)attack(%d points)",player_atk);
        gotoXY(26,9);
        printf("(2)escape");
        gotoXY(23,10);
        printf("Please input your action...>");
        scanf("%d",&option);
        clear(38,8,16,21);/*clear player's option*/
        if(option==1)/*attack*/
        {
            player_atk_decide=rand()%10;
            if(player_atk_decide>1)
            {
                gotoXY(23,7);
                printf("You hurt %s:",mon_name);
                gotoXY(23,8);
                printf("%d points!",player_atk);
                mon_life-=player_atk;
            }
            else/*critical hit*/
            {
                gotoXY(23,7);
                printf("Critical hit!");
                gotoXY(23,8);
                printf("You hit %s:",mon_name);
                gotoXY(26,9);
                printf("%d points!",player_c_atk);
                mon_life-=player_c_atk;
            }
        }
        else/*escape*/
        {
            hit_decide=rand()%10;
            if(hit_decide>1)/*80%*/
            {
                clear_battle_star(3);/*clear battle box*/
                return 2;
            }
            else
            {
                setColor(Magenta);
                gotoXY(23,7);
                printf("Oops, you miss the chance to escape");
                gotoXY(23,8);
                printf("when you look at a beutiful girl!\n");
                setColor(White);
            }
        }
        /*Monster Attack*/
        hit_decide=rand()%10;
        if(hit_decide<1)/*critical hit*/
        {
            gotoXY(23,10);
            printf("Critical hit!");
            gotoXY(23,11);
            printf("%s hits you:",mon_name);
            gotoXY(26,12);
            printf("%d points!",mon_c_hit);
            player_life-=mon_c_hit;
        }
        else
        {
            gotoXY(23,10);
            printf("%s hits you:",mon_name);
            gotoXY(26,11);
            printf("%d points!",mon_n_hit);
            player_life-=mon_n_hit;
        }
        gotoXY(21,15);
        system("pause");
        system("cls");
    }
    while(mon_life>0 && player_life>0);/*battle end*/
    /*result*/
    if(player_life<=0 && mon_life>0)
    {
        battle_star();
        clear_battle_star(9);
        allp->state=-1;
        return 0;/*player dead*/
    }
    else
    {
        battle_star();
        clear_battle_star(3);
        return 1;/*win*/
    }
}
void check_win_and_end(const int result,const int monster_num)
{
    if(result==1)
    {
        setColor(Green);
        gotoXY(23,5);
        printf("You win!");
        setColor(White);
        Sleep(1000);
        gotoXY(23,12);
        system("pause");
    }
    else if(result==2)
    {
        setColor(Yellow);
        gotoXY(23,5);
        printf("You sucessfully escape!");
        setColor(White);
        Sleep(1000);
        gotoXY(23,7);
        system("pause");
    }
    else if(result==0)
    {
        setColor(Red);
        gotoXY(28,5);
        printf("You are killed!");
        Sleep(1000);
        setColor(White);
        Sleep(1000);
    }
    system("cls");
}
void monster_encounter(int *section,all_monster allm,all_player *allp)
{
    /*introduce ultimate*/
    system("cls");
    gotoXY(4,4);
    introduction_ultimate_code();
    /*introduce end*/
    int result=0,monster_num=0;
    constexpr int monster_level[4]= {1,4,7,9}; /*LV: 1 4 7 9*/
    if(rand()%15<8) monster_num=0;/*hoed*/
    else if(rand()%15<4) monster_num=1;/*orc*/
    else if(rand()%15<2) monster_num=2;/*koloss*/
    else if(rand()%15<1) monster_num=3;/*Amurtaht*/
    system("cls");
    /*print interface*/
    battle_star();
    gotoXY(23,5);
    printf("You encounter %s !!!",allm.monsters[monster_num].name);
    gotoXY(23,7);
    setColor(Yellow);
    printf("%s",allm.monsters[monster_num].name);
    setColor(White);
    gotoXY(23,8);
    printf("Level:%d   HP:%d",allm.monsters[monster_num].level,allm.monsters[monster_num].hp);
    Sleep(1000);
    gotoXY(23,10);
    blank(0,1,0,0);/*stop*/
    system("cls");
    check_win_and_end(battle(monster_num,allm,allp),monster_num);
}
