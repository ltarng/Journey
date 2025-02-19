#ifndef MAP_H___
#define MAP_H___
constexpr int map_size=22;
void NPC_tips(const int *section,const int npc_t_num);
int map_event(const int *rx,const int *ry,int *section,all_player *allp);
int role_move(int x,int y,int *rx,int *ry,int *section,all_player *allp);
#endif // MAP_H___

