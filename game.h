#ifndef GAME_H___
#define GAME_H___
constexpr int status_num=4;
constexpr int mon_num=4;
constexpr int mon_name_len=25;
struct player_status
{
    int hp,atk;
};
struct all_player
{
    player_status player[status_num];
    int state=0;//0=normal,1=finish this game,-1=killed by monster;
};
struct monster
{
    char name[mon_name_len]="";
    int level,hp,atk;
};
struct all_monster
{
    monster monsters[mon_num];
};
int UltimateCode(int guess,int this_turn_low,int this_turn_high,const int low,const int high);
int battle(const int monster_num,const all_monster allm,all_player *allp);
void check_win_and_end(const int result,const int monster_num);
void monster_encounter(int *section,all_monster allm,all_player *allp);
#endif // GAME_H___
